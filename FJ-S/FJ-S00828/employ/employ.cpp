#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void rd(int &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
void rdl(ll &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
const int N=1e5+5;
const ll mod=998244353;
int n,m,a[N],b[N],s[N],num(0),P[N],ct(0);
ll act[N];
char c[N];
bool use[N];
ll ans(0);
void dfs(int p,int now){
    if(now>=m){
        ans+=act[n-p+1];ans%=mod;
        return;
    }
    if(p>n)return;
    for(int i(1);i<=n;++i){
        if(!use[i]){
            b[p]=i;use[i]=true;
            dfs(p+1,now+((a[i]>p-1-now)&(c[p]-'0')));
            use[i]=false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    rd(n);rd(m);act[0]=1;
    for(int i(1);i<=n;++i)act[i]=act[i-1]*i%mod;
    scanf("%s",c+1);
    for(int i(1);i<=n;++i)rd(a[i]);
    if(n<=18){
        dfs(1,0);
        printf("%lld\n",ans);
        return 0;
    }
    for(int i(1);i<=n;++i)if(c[i]-'0')++num;
    if(m==1){ans=1;
        for(int i(1),x(0);i<=n;++i){
            if(c[i]-'0'){
                ans=ans*(s[i-1]-x)%mod;++x;
            }
        }
        ans=ans*act[n-num]%mod;
        printf("%lld\n",(act[n]-ans+mod)%mod);
        return 0;
    }
    for(int i(1);i<=n;++i)++s[a[i]];
    for(int i(1);i<=n;++i)s[i]+=s[i-1];
    for(int i(1);i<=n;++i)if(c[i]-'0')P[++ct]=i;
    for(int i(1),x,y;i<(1<<ct);++i){
        x=y=0;ll A(1);
        for(int j(ct);j;--j){
            y=0;
            for(int k(j-1);k;--k)y+=((i>>k-1)&1);
            if((i>>j-1)&1){
                A=A*(s[n]-s[P[j]-1-y]-x)%mod;++x;
            }
        }A*=act[n-x];A%=mod;
        if(x>=m){
            if((x-m)&1)ans+=mod-A;
            else ans+=A;
        }
    }printf("%lld\n",ans%mod);
    return 0;
}