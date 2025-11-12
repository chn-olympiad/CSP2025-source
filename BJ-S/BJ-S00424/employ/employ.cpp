#include <iostream>
using namespace std;
#define N 505
int n,m,ans;
int p[N];
bool b[N];
char tm[N];
int jx[N];

void solve()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!(tm[i]-'0') || cnt>=jx[p[i]])
            cnt++;
    }
    if(n-cnt>=m)ans++;
}

void dfs(int d)
{
    if(d>n)
    {
        solve();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            b[i]=1;
            p[d]=i;
            dfs(d+1);
            b[i]=0;
        }
    }
}


int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>(tm+1);
    for(int i=1;i<=n;i++)
        cin>>jx[i];
    dfs(1);
    cout<<ans;
    return 0;
}
