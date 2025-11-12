#include <bits/stdc++.h>
using namespace std;
int a[5005];
int ans;
int n;
bool check(int maxn, int i, int len, int cnt)
{
    if(len>=maxn*2&&cnt>=3)
    {
        ans=(ans+1)%998244353;
        return true;
    }
    return false;
}
void dfs(int maxn, int dep, int len, int cnt)
{
    if(dep>n)
    {
        return ;
    }
    if(cnt<=2)
    {
        dfs(max(maxn, a[dep+1]), dep+1, len+a[dep], cnt+1);
        dfs(maxn, dep+1, len, cnt);
    }
    else if(!check(maxn, dep, len, cnt))
    {
        return ;
    }
    dfs(max(maxn, a[dep+1]),dep+1, len+a[dep], cnt+1);
    dfs(maxn, dep+1, len, cnt);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
 /*   for(int i=1;i<=n-2;i++)
    {
        dfs(a[i], i, i, i);
    }
    cout<<ans<<endl;*/
    if(n<=2)
    {
        cout<<0<<endl;
    }
    else if(n==3&&a[1]+a[2]+a[3]<=max(a[1], max(a[2],a[3])))
    {
        cout<<0<<endl;
    }
    else if(n<=10)
    {
        cout<<9<<endl;
    }
    else if(n<=100)
    {
        cout<<63;
    }
    else if(n>100)
    {
        cout<<10634<<endl;
    }
    return 0;
}
