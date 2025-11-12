#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,ans=0;
int a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0)
    {
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=1)
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            cout<<n/2;
            return 0;
        }
        else
        {
            bool flag=true;
            for(int i=1;i<=n;i++)
            {
                if(a[i]!=1 && a[i]!=0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                for(int i=1;i<=n;i++)
                {
                    if(a[i]==0) ans++;
                    if(a[i]==1 && a[i+1]==1) ans++,i++;
                }
                cout<<ans;
                return 0;
            }
        }
    }
    if(k==1)
    {
        bool vis=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=1 && a[i]!=0)
            {
                vis=false;
                break;
            }
        }
        if(vis)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
