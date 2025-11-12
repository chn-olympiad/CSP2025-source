#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=1e6+10;
const int base=13331;
const int mod=998244353;
int read()
{
    int w=1,s=0;
    char ch=getchar();
    while(ch<'0'||'9'<ch)
    {
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int n,m,ans=0;
string s;
int c[N],p[N],vis[N];
void dfs(int u)
{
    if(u==n+1)
    {
        int res=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(c[p[i]]<=sum||s[i-1]=='0')
            {
                sum++;
            }
            else res++;
        }
        if(res>=m)
        {
            ans++;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        p[u]=i;
        vis[i]=1;
        dfs(u+1);
        vis[i]=0;
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>s;
    for(int i=1;i<=n;i++) c[i]=read();
    dfs(1);
    cout<<ans%mod;
}
