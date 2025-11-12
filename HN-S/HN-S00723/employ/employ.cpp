#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int quickpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }return ret;
}
int fac[505],inv[505];
void init(int n=500){
    fac[0]=1;for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    inv[n]=quickpow(fac[n],mod-2);
    for(int i=n-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int n,m;
string s;
int cnt[505],sum[505];
int f[505][505],F[505][505];
int pop_count(int S){
    int ret=0;
    while(S){
        ret+=(S&1);
        S>>=1;
    }return ret;
}
int jiang(int x,int k){
    return fac[x]*inv[x-k]%mod;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    cin>>n>>m;
    cin>>s;s='#'+s;
    vector<int> pos;
    for(int i=1;i<=n;i++){
        int x;cin>>x;cnt[x]++;
    }
    sum[0]=cnt[0];
    for(int i=1;i<=n;i++) sum[i]+=sum[i-1]+cnt[i];
    for(int i=1;i<=n;i++){
        if(s[i]=='1') pos.push_back(i);
    }
    int k=pos.size();
    reverse(pos.begin(),pos.end()),pos.push_back(0);
    reverse(pos.begin(),pos.end());
    int ans=0;
    f[0][0]=1;
    int fail=0;
    int Ko=0;
    for(int i=1;i<=k;i++){
        fail+=pos[i]-pos[i-1]-1;
        for(int j=0;j<=k;j++){
            for(int ko=0;ko<=n;ko++){
                int Fail=fail+ko;
                F[j][ko]+=f[j][ko];
                if(F[j][ko]>=mod) F[j][ko]-=mod;
                if(j){
                    int xi=sum[Fail]-ko-(j-1);
                    xi=max(xi,0ll);
                    F[j][ko]-=f[j-1][ko]*xi%mod;
                    if(F[j][ko]<0) F[j][ko]+=mod;
                }
            }
        }
        for(int j=0;j<=k;j++){
            for(int ko=0;ko<n;ko++){
                int Fail=fail+ko;
                int xi=sum[Fail]-ko-j;
                xi=max(xi,0ll);
                F[j][ko+1]+=f[j][ko]*xi%mod;
                if(F[j][ko+1]>=mod) F[j][ko+1]-=mod;
            }
        }
        for(int j=0;j<=k;j++){
            for(int ko=0;ko<=n;ko++){
                f[j][ko]=F[j][ko];
                F[j][ko]=0;
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int ko=0;ko<=n;ko++){
            int win=k-ko;
            if(k-ko<m) continue;
            ans+=f[i][ko]*jiang(n-(ko+i),win-i)%mod;
        }
    }
    
    ans=(ans%mod+mod)%mod;
    cout<<ans*fac[n-k]%mod<<'\n';
}
/*

最后一次 CSPS，AK 了？人生第一次啊
CCF 别卡我常求你了

为什么在高二却输了呢。
lfxxx 24+10+5

3 1
111
0 0 1

255:0 0 0
1 0 0
2 0 1
3 0 1
4 0 1
5 0 1
6 0 2
7 0 2
*/