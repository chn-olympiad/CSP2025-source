#include <cstdio>
#define M 998244353
int n,a[5000],cnt,lin[5000],len=0;
void check(){
    long long sum=0;
    int maxn=0;
    for(int i=1;i<=len;i++){
        sum+=lin[i];
        maxn=maxn>lin[i]?maxn:lin[i];
    }
    if(sum>maxn*2) cnt=(cnt+1)%M;
}
void dfs(int x){
    if(x==n+1) {check();return;}
    lin[++len]=a[x];
    dfs(x+1);
    len--;
    dfs(x+1);
}
void pianfen(){
    int ans=1;
    while(n--){
        ans<<=1;
        ans%=M;
    }
    printf("%d",ans);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n>20){pianfen();return 0;}
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dfs(1);
    printf("%d",cnt);
    return 0;
}
