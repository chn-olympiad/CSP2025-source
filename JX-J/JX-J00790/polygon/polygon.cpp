#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],ans,ma;
void dfs(int now,int sum,int ma){
    if(now==n+1){
        if(sum>ma*2) ans++;
        return;
    }dfs(now+1,sum+a[now],max(ma,a[now]));
    dfs(now+1,sum,ma);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ma=max(a[i],ma);
    }if(ma==1){
        ans=(n-1)*(n-2)/2;
        printf("%lld\n",ans%mod);
        return 0;
    }dfs(1,0,0);
    printf("%lld\n",ans%mod);   
    return 0;
}