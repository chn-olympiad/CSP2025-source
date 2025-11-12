#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10;
int n,k,a[N],type=1,ans;
int main()
{
    freopen(xor.in,"r",stdin);
    freopen(xor.out,"w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=1) type=1;
        if(a[i]!=0) type=2;
    }
    if(type==0)
    {
        cout<<n/2;
    }
    if(type==1)
    {
        if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i])
                {
                    if(a[i+1]) ans++,i++;
                }
                else ans++;
            }
            cout<<ans;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]) ans++;
                else
                {
                    if(!a[i+1]) ans++,i++;
                }
            }
            cout<<ans;
        }
    }
    return 0;
}
