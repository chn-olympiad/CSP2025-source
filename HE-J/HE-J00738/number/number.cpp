#include<iostream>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     char s[100005];
     for(int i=1;i<=s;i++)
     {
         for(int j=1;j<=s;j++)
         {

             if(i<j)
             {
               cout<<i;
               break;
             }
             else{
                cout<<j;

             }
         }
     }

        return 0;
}
