#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
int n,m,c[505];
int b[505],book[505];
string s;
int dfs(int now)
{
    if(now==n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int j=b[i];
            if(s[i]=='0'||cnt>=c[j]) cnt++;
        }
        if(n-cnt>=m) return 1;
        return 0;
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(book[i]) continue;
        b[now+1]=i;book[i]=1;
        res+=dfs(now+1);res%=mod;
        book[i]=0;
    }
    return res;
}
signed main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;s=' '+s;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')
        {
            f=1;
            break;
        }
    }
    if(n<=20)
    {
        for(int i=1;i<=n;i++) cin>>c[i];
        cout<<dfs(0);
    }
    else if(!f)
    {
        int ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        cout<<ans<<endl;
    }
    else if(m==n&&f)
    {
        cout<<0;
    }
    return 0;
}
