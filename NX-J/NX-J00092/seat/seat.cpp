#include<bits/stdc++.h>
using namespace std;
int main(){
   int m,n;
   cin>>m>>n;
   int a[m][n];
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
       {


       cin>>a[i][j];

       if(a[i]>a[i-1])
       {

           swap(a[i,b[i-1]);
       }
       }
   }
       for(int i=1;i<=m,i++)
       {
           for(int j=1;j<=n;j++)
           {
               cout<<a[i][j];

           }

       }
   }

   return 0;
   }


