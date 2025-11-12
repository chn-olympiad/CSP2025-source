#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long ans;
int n,k[25],a[25],vis[25];
void dfs(int x,int sum,int ma){
    if(x>=3&&sum>2*ma){
        ans=(ans+1)%MOD;
    }
    if(x>n) return;
    for(int i=k[x-1]+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            k[x]=i;
            dfs(x+1,sum+a[i],max(ma,a[i]));
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1,0,0);
    printf("%lld",ans);
    return 0;
}
