#include <bits/stdc++.h>
using namespace std;
const int N=5005;
long n,ans;
int a[N];
void dfs(int x,int maxn,int step)
{
    if(step>a[maxn]) ans++,ans%=998244353;
    if(x+1>=maxn) return;
    for(int i=x+1;i<maxn;i++) dfs(i,maxn,step+a[i]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) dfs(0,i,0);
    cout<<ans;
    return 0;
}
