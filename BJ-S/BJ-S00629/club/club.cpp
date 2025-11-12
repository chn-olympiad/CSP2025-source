#include<iostream>
#include<algorithm>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
using namespace std;
typedef long long ll;
const int mod=1e9+7,maxn=1e5+5;
inline ll read(){
    ll res=0,p=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')p=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+(c-'0');
        c=getchar();
    }
    return res*p;
}
struct modint{
    ll x;
    inline modint(ll x_){
        x=x_%mod;
    }
    inline modint operator+(modint b){
        return {(x+b.x)%mod};
    }
    inline modint operator-(modint b){
        return {(x-b.x%mod+mod)%mod};
    }
    inline modint operator*(modint b){
        return {(x*b.x)%mod};
    }
};
inline modint qpow(modint a,ll b){
    modint res=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int cnt[10],a1[10];
int as[3][maxn];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int it;
    cin>>it;
    while(it--){
        int in=read();
        ll ans=0;
        rep(v1,0,2)cnt[v1]=0;
        rep(v1,1,in){
            int mx=0,m2=0;
            rep(v2,0,2){
                a1[v2]=read();
                if(a1[v2]>=a1[mx])mx=v2;
            }
            rep(v2,0,2)if(v2!=mx)m2=max(m2,a1[v2]);
            cnt[mx]++;
            ans+=a1[mx];
            as[mx][cnt[mx]]=a1[mx]-m2;
        }
        rep(v1,0,2)if(cnt[v1]>in/2){
            sort(&as[v1][1],&as[v1][cnt[v1]+1]);
            rep(v2,1,cnt[v1]-in/2)ans-=as[v1][v2];
        }
        printf("%lld\n",ans);
    }
    return 0;
}