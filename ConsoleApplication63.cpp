#include <iostream>
#include <string>
using namespace std;

void ReadNamefields(string arra[100], float expense[100] , int &laenNumber)
{
    laenNumber ;
   
    do
    {
        cout << "Enter  expense name(to stop [0])\n";
       
        cout << laenNumber + 1<<"_Name:";
        
        cin >> arra[laenNumber];
        if (arra[laenNumber] == "0")
            break;
        
        cout << "Expense:";
        cin >> expense[laenNumber];
        laenNumber++;
    } while (laenNumber< 100);
   
}

void DeleteNameOfexp(string arra[100], float expense[100], int& laenNumber)
{
    for (int j = 0; j < laenNumber; j++)
    {
        cout <<j+1<< "\n_Name :" << arra[j] << "\nexpense :" << expense[j] << endl;
    }
    string Sure;
   
    while (true)
    {  
        bool ih = false;
        cout << "Enter  Name\n";
        cin >> Sure;
        for (int i = 0; i < laenNumber ; i++)
        {
            if (Sure == arra[i])
            {
                for (int j = i; j < laenNumber - 1; j++)
                {
                    
                    arra[j] = arra[j + 1];
                    expense[j] = expense[j + 1];
                    
                    
                }
                laenNumber--;
                cout << "It has been deleted\n";
                ih = true;
                break;

            }
           
        }
         if (ih == false)
        {
            cout << "\nName not found\n";
        }
         if (ih )
        {
            break;
        }
    }
       
        
       
    
   
}

void Collectingtheexpenses(string arra[100], float expense[100], int laenNumber)
{
    float Sum = 0;

    for (int i = 0; i < laenNumber ; i++)
    {
        Sum += expense[i];
    }
    cout << "Total:" << Sum << endl;
}

void Print(string arra[100], float expense[100], int laenNumber)
{
    for (int i = 0;i< laenNumber ; i++)
        cout <<i+1<<"_Name:" << arra[i]<<"__"<<expense[i]<<endl;
}

void EditExpense(string arra[100], float expense[100], int laenNumber)
{
    Print(arra, expense, laenNumber);

    int Number;

    float amou;

    while (true)
    {
        cout << "Enter name number\n";

        cin >> Number;
        if (Number < laenNumber)
        {
            break;
        }
         if (Number<1 || Number>laenNumber)
        {
            cout << "Wrong Number\n";

         }

    }
    


     cout << "\nEnter the amount\n";

     cin >> amou;

     expense[Number - 1] = amou;



}

void EditName(string arra[100], float expense[100], int laenNumber)
{
   
    Print(arra, expense, laenNumber);
    
    string Name;
    
    int Number;

    while (true)
    {
        cout << "Enter name number\n";

        cin >> Number;

        if (Number < laenNumber)
        {
            break;
        }

        else if (Number<1 || Number>laenNumber)
        {
            cout << "Wrong Number\n";

        }

    }
        cout << "Enter a new name\n";

        cin >> Name;

        arra[Number - 1] = Name;

        cout << "The name has been changed\n";
    
}

void SearchName(string arra[100], float expense[100], int& laenNumber)
{
   
    while (true)
    {
        
        string Name;
        bool isuo = false;
        cout << "Enter name\n"; 
        cin >> Name;
        cout << "\n";
        for (int i = 0; i < laenNumber; i++)
        {
            if (Name == arra[i])
            {
                isuo = true;
                string NewName;
                cout << "New name\n";
                cin >> NewName;
                arra[i] = NewName;
               
               break;
            }
        }
        if (isuo == false)
        {
            cout << "\nName not found\n";
        }
        
    }
   
}

int PrintLoop()
{
    int Number;
    cout << "----------------------------"
        << "\n[1] Delete\n"
        << "[2] Total\n"
        << "[3] Print \n"
        << "[4] Edit expense\n"
        << "[5] Edit name\n"
        << "[6] New name  \n"
        << "[7] Exint\n"
        <<"----------------------------\n";
   
    cin >> Number;
    
    return Number;
}

void Loop(string arra[100], float expense[100], int& laenNumber)
{
   int NumberLoop;
   
   while (true)
    {
        NumberLoop = PrintLoop();
        if (NumberLoop == 1)
        {
            DeleteNameOfexp(arra, expense, laenNumber);
        }
        else if (NumberLoop == 2)
        {
            Collectingtheexpenses(arra, expense, laenNumber);
        }
        else if (NumberLoop == 3)
        {
            Print(arra, expense, laenNumber);
            
        }
        else if (NumberLoop == 4)
        {
            EditExpense(arra, expense, laenNumber);
        }
        else if (NumberLoop == 5)
        {
            EditName(arra, expense, laenNumber);
        }
        else if (NumberLoop == 6)
        {
            SearchName(arra, expense, laenNumber);
        }
        else if (NumberLoop == 7)
        {
            break;
        }
        else
        {
            cout << "Wrong Number\n";
        }
    }

}




int main()
{
    string arra[100];
    
    float expense[100];
    
    int laenNumber = 0;
    
    ReadNamefields(arra, expense, laenNumber);
    
    Loop(arra, expense, laenNumber);

    return 0;
}

