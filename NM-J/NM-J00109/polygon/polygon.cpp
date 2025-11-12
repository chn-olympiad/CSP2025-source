#include<bits/stdc++.h>
#define N 5005
using namespace std;
int n,ans;
int a[N];
void dfs(int pos,int sum,int maxn,int cnt)
{
    if(pos>n) return ;
    int tmax=max(maxn,a[pos]);
    if(cnt+1>=3&&a[pos]+sum>2*tmax) ans=(ans+1)%998244353;
    dfs(pos+1,sum+a[pos],tmax,cnt+1);
    dfs(pos+1,sum,maxn,cnt);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
