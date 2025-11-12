#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,sum,ans,a[5020];
void dfs(int num,int x){
    if(!num||x>n){
        if(sum>a[x-1]*2){
            ans++;
            if(ans>=998244353){
                ans=0;
            }
        }
        return;
    }
    for(int i=x;i<=n-num+1;i++){
        sum+=a[i];
        dfs(num-1,i+1);
        sum-=a[i];
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        dfs(i,1);
    }
    printf("%lld",ans);
    return 0;
}
