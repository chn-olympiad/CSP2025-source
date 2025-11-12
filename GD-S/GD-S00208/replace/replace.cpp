#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int maxn=2e5;
const int maxm=5e6;
const ll modx=998244353;
const ll mody=1e9+7;
const ll base=20090327;
ll pwx[maxm+5],pwy[maxm+5];
// ll ipwx[maxm+5],ipwy[maxm+5];
struct Hash{
    vector<ll> x;
    vector<ll> y;
    Hash(){
        x.clear();y.clear();
        x.emplace_back(0);
        y.emplace_back(0);
    }
    inline void Clear(){
        x.clear();y.clear();
        x.emplace_back(0);
        y.emplace_back(0);
    }
    inline void Eb(char ch){
        ll t=ch-'a'+1;
        ll tx=x.back();
        ll ty=y.back();
        x.emplace_back((tx*base+t)%modx);
        y.emplace_back((ty*base+t)%mody);
    }
    inline pii Get(int l,int r){
        ll tx=((x[r]-x[l-1]*pwx[r-l+1])%modx+modx)%modx;
        ll ty=((y[r]-y[l-1]*pwy[r-l+1])%mody+mody)%mody;
        return pii(tx,ty);
    }
};
int n,m,K;
char s[maxm+5],c[maxm+5];
Hash a[maxn+5],b[maxn+5];
int L[maxn+5],R[maxn+5],LN[maxn+5];
Hash t,p;
inline ll Fpow(ll x,int y,const int mod){
    ll rs=1;
    for(;y;x=x*x%mod,y>>=1)
        if(y&1) rs=rs*x%mod;
    return rs;
}
signed main(){
    // const double stim=clock();
    freopen("replace.in","r",stdin);
    // freopen("replace1.in","r",stdin);
    freopen("replace.out","w",stdout);
    
    pwx[0]=pwy[0]=1;
    for(int i=1;i<=maxm;i++){
        pwx[i]=pwx[i-1]*base%modx;
        pwy[i]=pwy[i-1]*base%mody;
    }
    // ipwx[maxm]=Fpow(pwx[maxm],modx-2,modx);
    // ipwy[maxm]=Fpow(pwy[maxm],mody-2,mody);
    // for(int i=maxm-1;i>=0;i++){
    //     ipwx[i]=ipwx[i+1]*base%modx;
    //     ipwy[i]=ipwy[i+1]*base%mody;
    // }
    int l,r;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s+1,c+1);
        K=strlen(s+1);
        l=r=0;
        for(int j=1;j<=K;j++){
            if(s[j]!=c[j]){
                if(!l) l=j;
                r=j;
            }
            a[i].Eb(s[j]);
            b[i].Eb(c[j]);
        }
        L[i]=l,R[i]=r,LN[i]=K;
    }
    int cnt;
    while(m--){
        scanf("%s%s",s+1,c+1);
        K=strlen(s+1);
        l=r=0;
        t.Clear(),p.Clear();
        for(int j=1;j<=K;j++){
            if(s[j]!=c[j]){
                if(!l) l=j;
                r=j;
            }
            t.Eb(s[j]);
            p.Eb(c[j]);
        }
        cnt=0;
        for(int j=1;j<=n;j++)
            if(t.Get(l,r)==a[j].Get(L[j],R[j])&&p.Get(l,r)==b[j].Get(L[j],R[j]))
                if(1<=l-L[j]+1&&r+LN[j]-R[j]<=K)
                    if(t.Get(l-L[j]+1,r+LN[j]-R[j])==a[j].Get(1,LN[j]))
                        cnt++;
        printf("%d\n",cnt);
    }
    
    // cerr<<endl<<(clock()-stim)/CLOCKS_PER_SEC;
    return 0;
}