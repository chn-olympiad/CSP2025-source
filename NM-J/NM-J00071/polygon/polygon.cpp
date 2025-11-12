#include<bits/stdc++.h>
using namespace std;
const int N=5010,P=998244353;
int n,a[N],ans;
void dfs(int x,int sum,int cnt,int mx){
    if(x>n){
        if(cnt>=3 && sum>mx*2) ans=(ans+1)%P;
        return ;
    }
    if(cnt+n-x+1>3) dfs(x+1,sum,cnt,mx);
    dfs(x+1,sum+a[x],cnt+1,max(mx,a[x]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++) scanf("%d",a+i),mx=max(mx,a[i]);
    if(n<3){
        printf("0");
        return 0;
    }
    if(mx==1){
        ans=1;
        for(int i=1;i<=n;i++) ans=(ans*2LL)%P;
        ans=(1LL*ans+1LL*P-1LL-1LL*n-1LL*n*(n-1LL)/2LL)%P;
        printf("%d",ans);
        return 0;
    }
    dfs(1,0,0,0);
    printf("%d",ans);
    return 0;
}
