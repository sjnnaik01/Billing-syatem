#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
private:
    int code;
    float price;
    float discount;
    string p_name;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void Remove();
    void list();
    void recipt();
};
void shopping:: menu()
{
    m:
    int choice;
    string email;
    string password;
    cout<<"\n\t______________________________________\t\n";
    cout<<"\n\t         supper market menu           \t\n";
    cout<<"\n\t         1) adminstartor              \t\n";
    cout<<"\n\t         2)buyer                      \t\n";
    cout<<"\n\t         3)exit                       \t\n";
    cout<<"\n\t         please select                \t\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
    {
        cout<<"\n\t     please login                 \t\n";
        cout<<"\n\t     enter the email              \t\n";
        cin>>email;
        cout<<"\n\t     enter the password           \t\n";
        cin>>password;
        if(email=="robby@email.com" && password=="12345678")
        {
            administrator();
        }
        else
        {
            cout<<"\n       invalid email/password      \n";
        }
        break;
    }
    case 2:
    {
        {
            buyer();

        }
    case 3:
        {
            exit(0);/*succesfull termination*/
        }
    default:
        {
            cout<<"please select from the given option";
        }

    }
goto m;
}
}
void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\n         administrator          \n";
    cout<<"\n       1) add the product            \n";
    cout<<"\n       2) modify the product         \n";
    cout<<"\n       3) delete the product         \n";
    cout<<"\n       4)back to main menu           \n";

    cout<<"\n\t     please enter your choice      \t\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            Remove();
            break;
        }
        case 4:
        {
            menu();
            break;
        default :
        cout<<"invalid choice";

        }

    }
    goto m;
}
void shopping::buyer()
{
    m:
    int choice;
    cout<<"\n\t_____________________buyer_________________________\t\n";
    cout<<"\n\t_________________1)buy product______________________\t\n";
    cout<<"\n\t_________________2)go back___________________________\t\n";
    cout<<"\n\t_________________enter your choice :__________________\t\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            recipt();
            break;
        }
    case 2:
        {
            menu();
    default:
        cout<<"\n\t_______________invalid choice_______________\t\n";
        }
    }
    goto m;
}
void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\t___________________add new product________________\t\n";
    cout<<"\n\t_________________product code of the product_______\t\n";
    cin>>code;
    cout<<"\n\t_________________name of the product________________\t\n";
    cin>>p_name;
    cout<<"\n\t_________________price of the product________________\t\n";
    cin>>price;
    cout<<"\n\t_________________discout on the product_______________\t\n";
    cin>>discount;

    data.open("datatbase.txt",ios::in);/*reading mode*/

    if(!data)
    {

        data.open("database.txt",ios::app|ios::out);/*writing mode*//*aapend mode*/
        data<<" "<<code<<" "<<p_name<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
        {
        data>>c>>n>>p>>d;
        while(!data.eof())  /*end of file fun*/
        {
            if(c ==code)/*to check the token code*/
            {
                token++;
            }
            data>>c>>n>>p>>d;/* read*/

        }
        data.close();

    if (token==1)
    {
        goto m;
    }
        else{
            data.open("database.txt",ios ::app|ios::out);
        data<<" "<<code<<" "<<p_name<<" "<<price<<" "<<discount<<"\n";
        data.close();
        }
}
        cout<<"record inserted :";
}
void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token =0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t_______________modify the record_____________\t\n";
    cout<<"\n\t___________enter the product code_____________\t\n";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {

        cout<<"file doesnt exist";
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data>>code>>p_name>>price>>discount;
        (!data.eof());
        {
            if(pkey==code)
            {
                cout<<"\n\t           product of new :           \t\n";
                cin>>c;
                cout<<"\n\t           enter the name :            \t\n";
                cin>>n;
                cout<<"\n\t           enter the price :            \t\n";
                cin>>p;
                cout<<"\n\t           discount :                    \t\n";
                cin>>d;data1<<" "<<n<<" "<<p<<" "<<d<<" \n";
                cout<<"\n\t            record edited                 \t\n";
                token++;
            }
            else{
                data1<<" "<<code<<" "<<p_name<<" "<<price<<" "<<discount<<"\n";

            }
            data>>code>>p_name>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {

            cout<<"record not found sorry";
        }
    }
}
void shopping::Remove()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\t           delete product        \t\n";
    cout<<"\n\t       enter the product code :   \t\n";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(data)
    {

        cout<<"file doesnt exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);/*writing mode*/
        data>>code>>p_name>>price>>discount;
        while(!data.eof())
              {
               if(code==pkey)
                    {
                        cout<<"\n\t    product removed succesfully:       \t\n";
                        token++;
                    }
                    else{
                        data1<<" "<<code<<" "<<p_name<<" "<<price<<" "<<discount<<"\n";

                    }
                    data>>code>>p_name>>price>>discount;
              }
              data.close();
              data1.close();
              remove("database.txt");
              rename("database1.txt","database.txt");
              if(token==0)
              {
                  cout<<"\n\t       record not found         \t\n";
              }
    }
}
void shopping:: list()
{
   fstream data;
   data.open("database.txt",ios::in);
   cout<<"p-roduct number:";
   cout<<" productnumber\t\name\t\ price\n";
   data>>code>>p_name>>price>>discount;
   while(data.eof())
   {

       cout<<code<<"  "<<p_name<<" "<<price<<"\n";
       data>>code>>p_name>>price>>discount;
   }
   data.close();

}
void shopping::recipt()
{
     m:
    fstream data;
    int arrc[100];/*array of codes*/
    int arrq[100];/*array of quantity*/
    string choice;
    int c=0;
    float amount=0;
    int discount=0;
    float total=0;

    cout<<"receipt ";
    data.open("database.txt",ios::in);/*reading mode*/
    if(!data)
    {
        cout<<"\n\tempty database\t\n";

    }
    else{
        data.close();
        list();
        cout<<"\n\t      place the oder    \t\n";
        do
  /*to run a spacific block of code*/
        {

        cout<<"\n\t     enter the product code :      \t\n";
        cin>>arrc[c];
        cout<<"\n\t      enter the quantity :           \t\n";
        cin>>arrq[c];
        for(int i=0;i<c;i++)
        {
            if(arrc[c]==arrc[i])
            {
                cout<<"\n\t     duplicate product code     \t\n";
                cout<<"\n\t     please try again           \t\n";
                goto m;
            }
        }
        c++;
        cout<<"\n\t do you want buy another product  \t\n";
        cin>>choice;
        }
  while(choice =="yes");

    cout<<"\n\t             receipt               \t\n";
    cout<<"\n product number \t product name \t price \t amount with discount \t\n";
  for(int i=0;i<c;i++)
  {
      data.open("database.txt",ios::in);
      data>>code>>p_name>>price>>discount;
      while(!data.eof())
      {

          if(code==arrc[i])
             {
                 amount=price*arrq[i];
                 discount=amount-(amount*discount/100);
                 total=total+discount;
                 cout<<code<<p_name<<price<<amount<<discount;
             }
             data>>code>>p_name>>price>>discount;
      }
      data.close();
  }
  cout<<"\n\t__________________________total amount ___________________________:"<<total;
  }
}
int main()
{
    shopping s;
    s.menu();

}


