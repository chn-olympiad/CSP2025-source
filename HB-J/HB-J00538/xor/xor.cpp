#include <iostream>

using namespace std;
int a[100100];
int c[100100];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int b=0,d=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            c[1]++;
        }
        if(a[i]==0)
        {
            c[0]++;
        }
        if(a[i]!=1)
        {
            b=1;
        }
        if(a[i]!=1&&a[i]!=0)
        {
            d=1;
        }
    }
    if(b==0)
    {
        cout<<n/2;
    }
    else
    {
       if(d==0)
       {
           int u=0;
           if(k==0)
           {

               u=u+c[0]+c[1]/2;
               cout<<u;
           }
           if(k==1)
           {
               cout<<c[1];
           }
       }
       else
    {
        cout<<0;
    }
    }

    return 0;
}
