#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=0;
int n;
long long a[5010];
long long C[5010][5010];
void dfs(int x,long long sum,long long maxn,int op)
{
    if(op==1)
    {
        if(sum*1ll>maxn*2*1ll)
        {
            ans++;
            ans%=mod;
        }
    }
    if(x==n+1)
    {
        return ;
    }
    dfs(x+1,sum+a[x],max(1ll*a[x],1ll*maxn),1);
    dfs(x+1,sum,maxn,0);
    return ;
}
int kl=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)
        {
            kl=1;
        }
    }
    for(int i=1;i<=n+1;i++)
    {
        C[i][1]=i;
        C[i][i]=1;
        for(int j=2;j<=i;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=mod;
        }
    }
    if(kl==1)
    {
        dfs(1,0,0,1);
    }
    else
    {
        long long mmm=0;
        for(int i=3;i<=n;i++)
        {
            mmm+=C[n][i]%mod;
        }
        cout<<mmm;
        return 0;
    }
    cout<<ans;
    return 0;
}
