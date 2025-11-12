#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int  maxn = 505;
int n,m;
char s1[maxn];
int s[maxn];
int c[maxn];  //耐心
int b[maxn];
int vis[maxn];
int ans; 
void check ()
{
    int p=0;  //没有过的人数
    for (int i=1;i<=n;i++)
    {
        if (!s[i]) {
            p++;  //inability
        }
        else {
            if (c[b[i]]<=p) //放弃
            {
                p++;
            }
        }
    }
    if ((n-p)>=m) ans++;

}

void dfs(int dep)
{
    if (dep==n+1)
    {
        check();
        return ;
        }
    for (int i=1;i<=n;i++)
    {
        if (vis[i]) continue;
        b[dep] = i;
        vis[i] = 1;
        dfs(dep+1);
        b[dep] = 0;
        vis[i]=0;
    }

}
bool checks()
{
    for (int i=1;i<=n;i++)
    {
        if (s[i]!=1) return 0;
    }
    return 1;
}
void work()
{
        if (checks())
        {
            ll sum =1;
            int cnt=0;
            for (int i=1;i<=n;i++)
            {
                if (c[i]==0) cnt++;
            }
            for (int i=1;i<=(n-cnt);i++)
    {
    sum = (sum*i)%998244353;
    }
    ans = sum;
        }
        else
    dfs(1);
    cout<<ans<<endl;
}

void input()
{
    cin>>n>>m;
    cin>>s1;
    for (int i=0;i<n;i++)
        s[i+1] = s1[i]-48;
    for (int i=1;i<=n;i++)
        cin>>c[i];
    work();
}

int main ()
{
    freopen("employ.in","r",stdin);
    freopen ("employ.out","w",stdout);
    input();
    return 0;
}