#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
string s;
priority_queue<int,vector<int>,greater<int> > q;
int n,m,num,an,kc,a[505],b[505],mod=998244353;
long long f[505];
bool vis[12];
void dfs(int x)
{
    if(x>n)
    {
        if(n-kc>=m)an++;
        return;
    }
    int i;
    bool w;
    for(i=1;i<=n;i++)
    {
        w=0;
        if(!vis[i])
        {
            vis[i]=1;
            if(kc>=a[i]||s[x-1]=='0')
                kc++,w=1;
            dfs(x+1);
            vis[i]=0;
            if(w)
                kc--;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int dq=0,t=0,x=0,i;
    cin>>n>>m>>s;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        if(s[i]=='0')
            t++;
    if(t==0)
    {
        long long ans=1;
        for(i=1;i<=n;i++)
            ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    if(n-t<m)
    {
        cout<<0;
        return 0;
    }
    while(dq<n)
    {
        dq++;
        b[dq]=n;
    }
    if(n<=10)
    {
        dfs(1);
        cout<<an;
        return 0;
    }
    sort(a+1,a+n+1);
    for(i=0;i<n;i++)
        if(s[i]=='0')
        {
            x++;
            while(dq<n&&a[dq+1]<=t)
            {
                dq++;
                b[dq]=i+1;
            }
        }
    f[0]=1;
    for(i=1;i<=n;i++)
    {
        while(!q.empty()&&q.top()<i)
            q.pop();
        f[i]=f[i-1]*(q.size()%mod+1);
        f[i]%=mod;
        q.push(b[i]);
    }
    cout<<f[n];
    return 0;
}