#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],ans;
bool flag=true,vis[500005];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
            flag=false;
    }
    if(flag&&k==0)
    {
        cout<<n/2;
        return 0;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1&&vis[i]==0)
            {
                ans++;
                vis[i]=1;
            }
            else if(abs(a[i]-a[i-1])==1&&vis[i]==0&&vis[i-1]==0)
            {
                vis[i]=1;
                vis[i-1]=1;
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    else if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0&&vis[i]==0)
            {
                ans++;
                vis[i]=1;
            }
            else if(a[i]==a[i-1]&&vis[i]==0&&vis[i-1]==0)
            {
                vis[i]=1;
                vis[i-1]=1;
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
