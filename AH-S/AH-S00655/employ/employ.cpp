#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=505,mod=998244353;
int n,m,s[N],c[N];

void add(ll &a,ll b){if ((a+=b)>=mod) a-=mod;}
ll ksm(ll k,int x){
    ll rt=1;
    while (x){
        if (x&1) rt=rt*k%mod;
        k=k*k%mod,x>>=1;
    }
    return rt;
}
ll jc[N],invjc[N];
void prejc(){
    jc[0]=invjc[0]=1;
    up(i,1,n) jc[i]=jc[i-1]*i%mod,invjc[i]=ksm(jc[i-1],mod-2);
}
ll C(int a,int b){return jc[a]*invjc[b]%mod*invjc[a-b]%mod;}

namespace sub15{
    void solve(){
        up(i,1,n) if (s[i]==0||c[i]==0){
            cout<<0;
            return;
        }
        cout<<jc[n];
    }

}

namespace solve1{
    int p[15];
    void solve(){
        up(i,1,n) p[i]=i;
        int ans=0;
        do{
            int cnt=0;
            up(i,1,n) if (cnt>=c[p[i]]||s[i]==0) cnt++;
            if (cnt<=n-m) ans++;
        }while (next_permutation(p+1,p+n+1));
        cout<<ans;
    }
}

namespace solve2{
    ll buc[N],f[N],tmp[N];
    ll calc(int mk){
        up(i,0,n+1) buc[i]=f[i]=0;
        up(i,1,n+1){
            if (mk>>i-1&1) buc[c[i]]++;
        }
        up(i,1,n+1) buc[i]+=buc[i-1];
        f[0]=1;
        up(i,1,n){
            if (s[i]==0){
                down(j,n,0) add(f[j],f[j-1]*buc[n+1]%mod);
            }
            else{
                down(j,n,0){
                    ll tmp=0;
                    add(tmp,f[j]*(buc[n+1]-buc[j])%mod);
                    add(tmp,f[j-1]*buc[j-1]%mod);
                    f[j]=tmp;
                }
            }
        }
        ll rt=0;
        up(i,n-m+1,n) add(rt,f[i]);
        return rt;
    }
    void solve(){
        ll ans=0;
        up(mk,1,(1<<n)-1){
            int ppc=__builtin_popcount(mk);
//            cout<<mk<<" cehck "<<calc(mk)<<'\n';
            if ((n-ppc)&1) add(ans,mod-calc(mk));
            else add(ans,calc(mk));
        }
        cout<<(jc[n]-ans+mod)%mod;
    }
}

namespace sub12{
    ll buc[N];
    void solve(){
        up(i,1,n) buc[c[i]]++;
        ll tot=0,res=0,ans=1;
        up(i,1,n){
            tot+=buc[i-1];
            if (s[i]==0){
                res++;
                continue;
            }
            if (tot==0){
                ans=0;
                break;
            }
            ans=ans*tot%mod;
            tot--;
        }
        ans=ans*jc[res]%mod;
        cout<<(jc[n]-ans+mod)%mod;
    }
}

namespace AC{

    ll f[N][N<<1],tmp[N][N<<1],buc[N<<1];
    //f[cnt][t]表示有cnt人被拒绝
    void solve(){
        up(i,1,n) buc[c[i]]++;
        ll tot=0,res=0;
        f[0][0]=1;
        tot=buc[0];
        up(i,1,n){
            tot+=buc[i];
            if (s[i]==0){
                res++;
                continue;
            }

            up(cnt,0,i) up(t,0,tot) tmp[cnt][t]=0;
            up(cnt,0,i){
                up(t,0,tot){
                    ll cntt=tot-buc[i]-t;
                    if (cntt<0) continue;
                    up(x,0,min(buc[i],cntt)){
                        add(tmp[cnt][t+buc[i]-x],f[cnt][t]*C(cntt,x)%mod*jc[x]%mod);
                    }
                }
            }
            up(cnt,0,i) up(t,0,tot) f[cnt][t]=0;
            up(cnt,0,i-1){
                up(t,0,tot){
                    if (tmp[cnt][t]==0) continue;
                    add(f[cnt][t],tmp[cnt][t]);
                    if (t>0) add(f[cnt+1][t-1],tmp[cnt][t]);
                }

            }
        }
        ll ans=0;
        up(cnt,n-m+1,n) up(t,0,n) add(ans,f[cnt][t]);
        ans=ans*jc[res]%mod;
        cout<<(jc[n]-ans+mod)%mod;
    }

}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    prejc();
    up(i,1,n){
        char x;cin>>x;
        s[i]=x-'0';
    }
    up(i,1,n) cin>>c[i];
    sort(c+1,c+n+1);
    if (n<=10){
        solve1::solve();
        return 0;
    }
    if (n<=18){
        solve2::solve();
        return 0;
    }
    if (m==n){
        sub15::solve();
        return 0;
    }
    if (m==1){
        sub12::solve();
        return 0;
    }
    else AC::solve();
    return 0;
}
