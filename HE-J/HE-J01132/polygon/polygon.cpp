#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
int ans=0;
vector<int>f[5005];
void dfs(int l,int now,int mx,int le)
{
    if(le>=3&&now>mx*2)ans=(ans+1)%998244353;
    for(int i=l+1;i<=n;i++)
    {
        dfs(i,now+a[i],max(mx,a[i]),le+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int tg=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)tg=0;
    }
    if(tg)
    {
        for(int i=1;i<=n;i++)
        {
            f[i].resize(i+1);
            f[i][1]=1;
            for(int j=2;j<=i;j++)
            {
                f[i][j]=(f[i-1][j-1]+f[i][j-1])%998244353;
            }
        }
        // for(int i=3;i<=n;i++)
        // {
        //     ans=(ans+f[n][i])%998244353;
        // }
        ans=f[n][n];
    }
    else
    dfs(0,0,0,0);
    cout<<ans<<'\n';
    return 0;
}