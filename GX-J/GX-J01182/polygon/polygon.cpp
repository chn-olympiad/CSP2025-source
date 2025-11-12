#include<bits/stdc++.h>
using namespace std;
long long const M=998244353;
long long n,a[5009],ans;
void dfs(long long plg,long long pos,long long ma,long long su,long long nw){
    if(plg==nw){
            if(su>2*ma){
                ans++;
                ans%=M;
            }
        return;
    }
    if(pos==n){
        return;
    }
    for(int i=pos+1;i<=n-(plg-nw)+1;i++){
        dfs(plg,i,max(ma,a[i]),su+a[i],nw+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n-i+1;j++)
            dfs(i,j,a[j],a[j],1);
    }
    printf("%lld",ans);
    return 0;
}
