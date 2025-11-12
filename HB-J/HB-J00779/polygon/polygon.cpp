#include<iostream>
#include<cstdio>
using namespace std;
int a[5010];
int n;
long long ans=0;
void dfs(long long x,int sum,long long mx,int f){
    if(sum>mx*2&&x>3&&f==1){
        ans++;
        ans%=998244353;
    }
    if(x>n){
        return;
    }
    dfs(x+1,sum,mx,0);
    dfs(x+1,sum+a[x],max(mx,(long long)a[x]),1);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1,0,0,0);
    printf("%lld\n",ans);
    return 0;
}