#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int mod=998244353;
const int N=500+9;
int a[N];
int n,m;
string s;

int cnt=0;
bool vis[N];
void dfs(int acc,int fai,int now)
{
    if(now==n)
    {
        if(acc>=m)
        {
            cnt++;
            cnt%=mod;
        }
        return ;
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;

        vis[i]=true;
        if(s[now]=='0')
        {
            dfs(acc,fai+1,now+1);
            vis[i]=false;
            continue;
        }
        if(fai>=a[i])
        {
            dfs(acc,fai+1,now+1);
            vis[i]=false;
            continue;
        }
        dfs(acc+1,fai,now+1);
        vis[i]=false;
    }

    return ;
}
void solved1()
{
    dfs(0,0,0);
    cout << cnt ;
    return ;
}
void solved2()
{
    int num=0;
    for(int i=1;i<=n;i++) if(a[i]!=0) num++;

    if(num<m)
    {
        cout << 0 ;
        return ;
    }

    int ans=1;
    for(int i=num;i>=1;i--) ans=(1ll*ans*i)%mod;
    cout << ans ;

    return ;
}
void solved3()
{
    for(int i=1;i<=n;i++) if(a[i]==0)
    {
        cout << 0 ;
        return ;
    }

    for(int i=0;i<s.size();i++) if(s[i]=='0')
    {
        cout << 0 ;
        return ;
    }

    int ans=1;
    for(int i=n;i>=1;i--) ans=(1ll*ans*i)%mod;
    cout << ans ;
}
void solved()
{
    cin >> n >> m ;
    cin >> s ;
    for(int i=1;i<=n;i++) cin >> a[i] ;

    bool flag=true;
    for(int i=0;i<s.size();i++) if(s[i]!=1) flag=false;
    if(flag)
    {
        solved2();
        return ;
    }

    if(m==n)
    {
        solved3();
        return ;
    }

    if(n<=10)
    {
        solved1();
        return ;
    }

    return ;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    int t;  cin >> t ;  while(t--)
    solved();

    return 0;
}
