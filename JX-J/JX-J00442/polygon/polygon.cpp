#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int ans=0;
int a[5010];
void dfs(int x,int xmax,int sum,int y){
    if(x>n){
        return;
    }
    if(y>=3&&xmax*2<sum){
        ans++;
        ans%=MOD;
    }
        for(int i=x+1;i<=n;i++){
            dfs(i,max(xmax,a[i]),sum+a[i],y+1);
        }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
        dfs(0,a[0],a[0],0);
    printf("%d",ans);
    return 0;
}
