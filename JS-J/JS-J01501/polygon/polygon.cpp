#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n;int point;
int a[5002];
int ans;
int sum[5002];
void dfs(int k,int sum1){
    if(k==point){
        if(sum1>a[point])
            ans++,ans%=Mod;
        return ;
    }
    dfs(k+1,sum1+a[k]);
    dfs(k+1,sum1);
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(point=3;point<=n;point++){
        dfs(1,0);
    }
    printf("%d",ans);
    return 0;
}
