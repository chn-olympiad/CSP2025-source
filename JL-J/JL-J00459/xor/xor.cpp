#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],vis[N];
int n,k;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) ans++,vis[i]=1;
            else if(a[i-1]==1 && vis[i-1]==0) ans++,vis[i-1]=vis[i]=1;
        }
        cout<<ans;
        return 0;
    }
    else if(k==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1) ans++;
        cout<<ans;
        return 0;
    }
    else
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k) ans++,vis[i]=1;
            else
            {
                int cnt=0;
                for(int j=i;j>=1;j--)
                {
                    if(vis[j]==1) break;
                    cnt^=a[j];
                    if(cnt==k)
                    {
                        ans++;
                        for(int s=i;s>=j;s--) vis[s]=1;
                        break;
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
