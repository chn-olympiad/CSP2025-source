#include<bits/stdc++.h>
#define rg register
#define ll long long
using namespace std;
const ll inff=998244353;
ll n,ans=0;
ll a[5010],ds[5010];
ll rd(){
    char c;
    int x=0,sig=1;
    for(c=getchar();c<'0'||c>'9';c=getchar())
        if(c=='-')sig=-1;
    for(;c>='0'&&c<='9';c=getchar())
        x=x*10+c-48;
    return x*sig;
}
inline void dfs(ll p,ll h,ll la){
    if(h==1){
        ll dd=n;
        while(p<=a[dd]&&dd>=la)dd--;
        ans=(ans+dd-la)%inff;
 //       if(dd>la)cout<<p<<endl;
        return;
    }
    for(rg ll i=la+1;i<=n-h+1;i++){
        dfs(p+a[i],h-1,i);
    }
}
void work(){
    n=rd();
    for(rg ll i=1;i<=n;i++){
        a[i]=rd();
    }
    sort(a+1,a+1+n);
//    build(1,1,n);
    for(rg ll k=3;k<=n;k++){
        dfs(0,k,0);
    }
    printf("%lld",ans);
}
void fre(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
}
int main(){
  fre();
    work();
    return 0;
}
