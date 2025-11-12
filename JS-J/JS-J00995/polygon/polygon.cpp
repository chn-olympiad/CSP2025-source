#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5010],f;
long long ans,t;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int k,int num,int now){

    if(num>a[k]){
        double m=n-now+1;
        t=(t+(long long)pow(2.0,m))%mod;
        return;
    }

    if(now==n+1){
        //if(num>a[k]) t=(t+1)%mod;
        return;
    }

    dfs(k,num,now+1);
    dfs(k,num+a[now],now+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=a[1]) f=1;
    }
    if(f==0){
        long long tot=((long long)pow(2.0,n)-1-n-n*(n-1)/2)%mod;
        printf("%lld\n",tot);
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n-2;i++){
        t=0;
        dfs(i,0,i+1);
        ans+=t%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
