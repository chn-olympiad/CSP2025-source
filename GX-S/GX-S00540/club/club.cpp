#include<bits/stdc++.h>
using namespace std;
long long a[4];
int c[4];
long long d[4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long i,t,m,n,x,j,y,b=1;

    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        int max=-1000;
        for(j=1;j<=n;j++)
        {
           for(x=1;x<=3;x++)
           {
               cin>>y;
               if(y>max&&c[b]<=n/2)
               {
                   max=y;
                   a[b]=a[b]+max;
                   b++;
               }
               else
               {
                   continue;

               }
           }
        }
        d[j]=d[j]+a[j];
    }
    for(i=1;i<=t;i++)
    {
        cout<<d[i]<<endl;
    }
    return 0;
}
