#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,a[5005];
long long sum,ans,b;
void dfs(int dep,int k){
    if(dep>n){
        if(k>=3&&sum>2*b) ans++;
        return ;
    }
    long long tmp=b;
    sum+=a[dep],b=a[dep];
    dfs(dep+1,k+1);
    sum-=a[dep],b=tmp;
    dfs(dep+1,k);
}
long long mod_x(long long a){
    long long c=mod-2,res=1;
    while(c){
        if(c&1) res=res*a%mod;
        c>>=1;a=a*a%mod;
    }
    return res;
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    //n<=20
    if(n<=20){
        dfs(1,0);
        printf("%lld\n",ans);
    }else{
        //max_a_i<=1
        sum=ans=1;
        for(int i=n;i>=4;i--){
            sum=sum*mod_x(n-i+1)%mod*i%mod;
            ans=(ans+sum)%mod;
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int T=1;//scanf("%d",&T);
    while(T--) solve();
    return 0;
}
