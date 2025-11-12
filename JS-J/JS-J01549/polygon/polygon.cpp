#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,P=998244353;
int n,a[N],ans;
void dfs(int k,int sum,int maxn,int cnt){
    if(k>n){
        if(cnt>=3&&sum>maxn*2){
            ans++;
            if(ans==P) ans=0;
        }
        return;
    }
    dfs(k+1,sum+a[k],a[k],cnt+1);
    dfs(k+1,sum,maxn,cnt);
}
int f[2][10005];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int S=1;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        S=(S<<1)%P;
    }
    sort(a+1,a+n+1);
    if(n<=20){
        dfs(1,0,0,0);
        printf("%lld",ans);
        return 0;
    }
    int MAXN=a[n];
    int x=0,y=1;
    f[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=a[i];++j) ans=(ans+f[x][j])%P;
        for(int j=0;j<=MAXN;++j) f[y][j]=f[x][j];
        for(int j=0;j+a[i]<=MAXN;++j){
            f[y][j+a[i]]+=f[x][j];
            f[y][j+a[i]]%=P;
        }
        swap(x,y);
    }
    printf("%lld",(S-ans-1+P)%P);
    return 0;
}
