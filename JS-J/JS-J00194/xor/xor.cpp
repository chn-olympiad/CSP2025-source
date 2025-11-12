#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fff(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
}
ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
void write(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
ll n,k;
ll a[500005],sum,flb=true,cnt,ans=1;
struct seg{
    ll l,r;
}g[500005];
bool cmp(seg a,seg b){
    return a.r<b.r;
}
void solveA(){
    printf("%d\n",n/2);
}
void solveB(){
    ll cnt1=0;
    for(ll i=1;i<=n;i++){
        cnt1+=(a[i]==1);
    }
    if(k==1) printf("%d\n",cnt1);
    else printf("%d\n",cnt1/2);
}
void solve(){
    for(ll i=1;i<=n;i++){
        if(a[i]==k)
            g[++cnt].l=i,g[cnt].r=i;
        ll las=a[i];
        for(ll j=i+1;j<=n;j++){
            las^=a[j];
            if(las==k)
                g[++cnt].l=i,g[cnt].r=j;
        }
    }
    sort(g+1,g+1+cnt,cmp);
    ll lasr=g[1].r;
    if(cnt==0){
        puts("0");
        return;
    }
    for(ll i=2;i<=cnt;i++){
        if(g[i].l>lasr) ++ans,lasr=g[i].r;
    }
    printf("%d\n",ans);
}
signed main(){
    fff();
    n=read(),k=read();
    for(ll i=1;i<=n;i++){
        a[i]=read(),sum+=a[i];
        if(a[i]!=0&&a[i]!=1) flb=false;
    }
    if(sum==n){
        solveA();
        return 0;
    }
    if(flb){
        solveB();
        return 0;
    }
    solve();
    return 0;
}
