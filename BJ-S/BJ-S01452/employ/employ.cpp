#include <iostream>
#include <algorithm>
using namespace std;
int n,m,ans,mod=998244353;
string s;
int c[505];
int sc[505];
bool used[505];
int p[505];
void dfs(int step)
{
    if (step>n)
    {
        int away=0,in=0;
        for (int i=1;i<=n;i++)
        {
            if (s[i-1]=='0')
                away++;
            else if (away>=c[p[i]])
                away++;
            else
                in++;
        }
        if (in>=m) ans=(ans+1)%mod;
        return ;
    }
    for (int i=1;i<=n;i++)
        if (!used[i])
        {
            used[i]=1;
            p[step]=i;
            dfs(step+1);
            used[i]=0;
        }
}
bool cmp(int x,int y)
{
    if (x==0) return 0;
    if (y==0) return 1;
    return x<y;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    int peo=0;
    bool flag=1;
    for (int i=1;i<=n;i++)
    {
        cin >> c[i];
        if (c[i]==0) peo++;
        if (s[i-1]=='0')
        {
            flag=0;
            break;
        }
    }
    if (flag)
    {
        if (n-peo<m)
        {
            cout << 0;
            return 0;
        }
        ans=1;
        for (int i=1;i<=n-peo;i++)
            ans=ans*i%mod;
        for (int i=1;i<=peo;i++)
            ans=ans*i%mod;
        cout << ans;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}
