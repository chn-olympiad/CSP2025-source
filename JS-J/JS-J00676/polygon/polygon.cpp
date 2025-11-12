#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,maxn,ls=0,jc[5005];
const int mod=998224353;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x,int y){
    if(ls>maxn&&y>=3){
        ans=(ans+jc[n-x])%mod;
        return;
    }
    for(int i=x+1;i<=n;i++){
        ls=(ls+a[i])%mod;
        dfs(i,y+1);
        ls=(ls-a[i]+mod)%mod;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    jc[0]=1;
    jc[1]=2;
    for(int i=2;i<=n;i++){
        jc[i]=(jc[i-1]*2)%mod;
    }
    for(int i=1;i<=n-2;i++){
        maxn=a[i];ls=0;
        dfs(i,1);
    }
    printf("%d",ans);
    return 0;
}
