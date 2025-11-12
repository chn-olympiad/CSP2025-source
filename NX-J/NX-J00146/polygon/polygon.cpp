#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxx,s,ans,gs;
int a[1000010],n;
void dfs(int x)
{
    if(x>n)
    {

        if(s>maxx*2&&gs>=3)
        {
            ans++;
            ans%=998224353;
        }
        return;
    }
    int te=maxx;
    maxx=max(maxx,a[x]);
    s+=a[x];
    gs++;
    dfs(x+1);
    gs--;
    maxx=te;
    s-=a[x];
    dfs(x+1);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1);
    cout<<ans;
    return 0;
}

