#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m;
char s[N];
int c[N];
int p[N],book[N];
int res=0;
void dfs(int u)
{
    if(u==n+1)
    {
        int fa=0;
        int acc=0;
        for(int i=1;i<=n;i++)
        {
            if(fa<c[p[i]]&&s[i]=='1')acc++;
            else fa++;
        }
        if(acc>=m)res++,res%=mod;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!book[i])
        {
            book[i]=1;
            p[u]=i;
            dfs(u+1);
            book[i]=0;
        }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;int chkA=1;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=20)
    {
        dfs(1);
        cout<<res<<endl;
    }
    else if(m==n)
    {
        int boo=1;
        for(int i=1;i<=n;i++)
            if(s[i]=='0'||c[i]==0)boo=0;
        if(!boo)cout<<0<<endl;
        else
        {
            int ans=1;
            for(int i=1;i<=n;i++)ans=ans*i%mod;
            cout<<ans<<endl;
        }
    }
    else cout<<0<<endl;
    return 0;
}
