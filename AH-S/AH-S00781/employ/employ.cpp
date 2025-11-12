#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
bool s[20],f[20];
int C[20],n,m;
int dfs(int c,int w)
{
    if(c==n+1)
        return (n-w>=m);
    if(n-w<m)
        return 0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i])
            continue;
        f[i]=1;
        if(s[c]||w>=C[i])
            ans=(ans+dfs(c+1,w+1))%mod;
        else
            ans=(ans+dfs(c+1,w))%mod;
        f[i]=0;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        s[i]=(c=='0');
    }
    for(int i=1;i<=n;i++)
        cin>>C[i];
    cout<<dfs(1,0);
}