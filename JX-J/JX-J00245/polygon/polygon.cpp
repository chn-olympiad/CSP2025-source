#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
void dfs(long long i,long long maxn,long long res)
{
    if(res>2*maxn)ans++;
    if(i==n+1)return;
    for(long long j=i+1;j<=n;j++)
    {
        dfs(j,max(maxn,a[j]),res+a[j]);
    }

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
