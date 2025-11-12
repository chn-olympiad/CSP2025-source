#include <iostream>
#include <algorithm>
using namespace std;
char c[510];
int n,m,ans,a[510];
int p[510],vis[510];
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int step)
{
    if(step>n)
    {
        int cnt=0,px=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]=='0'||a[p[i]]<=px)   px++;
            else    cnt++;
        }
        if(cnt>=m)
        {
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            p[step]=i;
            dfs(step+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)   cin >> c[i];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n<=10)
    {
        dfs(1);
        cout << ans << endl;
    }
    else if(m==n)
    {
        bool fl=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]=='0')   fl=1;
        }
        sort(a+1,a+n+1,cmp);
        if(a[n]==0) fl=1;
        long long sum=1,mod=998244353;
        for(int i=1;i<=n;i++)
        {
            sum=sum*(i*1ll);
            sum%=mod;
        }
        if(fl==1)   cout << "0" << endl;
        else    cout << sum << endl;
    }
    else
    {
        int cnt1=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]=='1')   cnt1++;
        }
        if(cnt1<m)  cout << "0" << endl;
    }
    return 0;
}
