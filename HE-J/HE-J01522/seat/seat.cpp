#include<iostream>
using namespace std;
int a[105],b[105][105],s[1][1];
int main()
{
     freopen("seat.in","r",stdin);
     freopen("seat.out","w",stdout);
     int n,m;
     cin>>n>>m;
     for(int i=1;i<=n*m;i++)
     {
         cin>>a[i];
     }
     int f=a[1];
     for(int i=1;i<=n;i++)
     {

         for(int j=1;j<=m;j++)
         {

             cin>>b[i][j];

         }
     }
     for(int q=1;q<=n*m;q++)
     {

         if(a[q]<a[q+1])
        {
                int c=a[q];
                a[q]=a[q+1];
                a[q+1]=c;

             for(int i=1;i<=n;i++)
             {

                 for(int j=1;j<=m;j++)
                 {

                     s[1][1]=b[i][j];
                     b[i][j]=b[i+1][j+1];
                     b[i+1][j+1]=s[1][1];

                 }
                 cout<<f;
             }
         }

     }



    return 0;
}
