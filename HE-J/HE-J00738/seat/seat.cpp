#include<iostream>
using namespace std;
int main()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=10;i++)
   {

       i=n;

   }
   for(int j=1;j<=10;j++)
   {

       j=m;
   }
    for(int p=1;p<=n*m;p++)
    {
        cin>>p;

        if(p[i]>p[num])
        {

            cout<<p[num][n][m];
        }
        else if
            (p[i]<p[num])
        {

            cout<<p[i][n][m];
        }

    }

        return 0;
}
