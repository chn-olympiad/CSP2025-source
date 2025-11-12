#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("polygon.in","r",stdin);
        freopen("polygon.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
using ll=long long;
const int N=5e3+11,Q=998244353;
int n,m;
int c[N];
ll f[N];
ll fac[N],ifac[N];
ll qp(ll a,int k) {
    ll rs=1;
    for(;k;k>>=1,a=a*a%Q)
        if(k&1) rs=rs*a%Q;
    return rs;
}
ll C(int n,int m) { return n<m?0:fac[n]*ifac[m]%Q*ifac[n-m]%Q; }
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x; cin>>x;  
        m=std::max(m,x);
        c[x]++;
    }
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%Q;
    ifac[n]=qp(fac[n],Q-2);
    for(int i=n-1;i>=0;i--)
        ifac[i]=ifac[i+1]*(i+1)%Q;
    ll rs=0;
    f[0]=1;
    for(int i=1;i<=m;i++) {
        if(c[i]) {
            ll t=0;
            for(int j=0;j<=i;j++)
                (t+=f[j])>=Q?t-=Q:0;
            // (t=qp(2,c[i-1]+c[i]-1)+Q-t)>=Q?t-=Q:0;
            // db("%d: %lld\n",i,t);
            t=(C(c[i],2)+t*c[i]%Q)%Q;
            (rs+=t)>=Q?rs-=Q:0;
        }
        for(int j=m;j>=0;j--) {
            for(int k=1;k<=std::min(c[i],j/i);k++)
                (f[j]+=f[j-i*k]*C(c[i],k)%Q)>=Q?f[j]-=Q:0;
        }
    }
    (rs=qp(2,n)+Q-rs)>=Q?rs-=Q:0;
    (rs+=Q-1)>=Q?rs-=Q:0;
    cout<<rs<<'\n';
    return 0;
}