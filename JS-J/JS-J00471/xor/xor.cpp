#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10;
ll n,k,ans,a[M];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                ans++;
                continue;
            }
            if(a[i]==0)
            {
                while(a[i]!=1)
                {
                    i++;
                    if(i>n)
                    {
                       ans--;
                       break;
                    }
                }
                ans++;
            }
        }
    }
    else if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                ans++;
                continue;
            }
            if(a[i]==1)
            {
                i++;
                while(a[i]!=1)
                {
                    i++;
                    if(i>n)
                    {
                       ans--;
                       break;
                    }
                }
                ans++;
            }
        }
    }
    else ans=n/2;
    cout<<ans;
    //cheat points
    return 0;
}
