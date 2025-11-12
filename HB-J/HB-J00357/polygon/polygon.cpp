#include <bits/stdc++.h>
using namespace std;
int b[5005]={};
int n,a;
bool m=1;
unsigned long long int sl=0,p=1,q=1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        b[i]=a;
    }
    if(n==3)
    {
        if(b[1]+b[2]>b[3] && b[2]+b[3]>b[1] && b[1]+b[3]>b[2])
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(b[i]!=1)
            {
                m=0;
                break;
            }
        }
        if(m)
        {
            for(int i=3;i<=n;++i)
            {
                for(int j=1;j<=i;++j)
                    p=p*j%998244353;
                for(int l=n;l>=n-i;--l)
                    q=q*l%998244353;
                sl=sl+q/p;
                sl=sl%998244353;
            }
            cout<<sl;
        }
    }
    return 0;
}
