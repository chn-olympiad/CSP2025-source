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
int f[20][20];
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
    freopen("employ1.in","r",stdin);
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
    if(pos.size()<=18){
        int k=pos.size();
        reverse(pos.begin(),pos.end()),pos.push_back(0);
        reverse(pos.begin(),pos.end());
        int ans=0;
        for(int S=0;S<(1<<k);S++){
            if(pop_count(S)<m) continue;
            memset(f,0,sizeof(f));
            f[0][0]=1;int fail=0;
            int ko=0;
            // cout<<S<<':';
            for(int i=1;i<=k;i++){
                fail+=pos[i]-pos[i-1]-1;
                // cout<<win<<' '<<ko<<" "<<fail<<'\n';
                if((S>>(i-1))&1){
                    for(int j=0;j<=k;j++){
                        f[i][j]=f[i-1][j];
                        if(j){
                            int xi=(sum[fail]-ko-(j-1));
                            xi=max(xi,0ll);
                            f[i][j]-=f[i-1][j-1]*xi%mod;
                        }
                    }
                }
                else{
                    for(int j=0;j<=k;j++){
                        int xi=(sum[fail]-ko-j);
                        xi=max(xi,0ll);
                        f[i][j]=f[i-1][j]*xi%mod;
                    }
                    fail++;
                    ko++;
                }
            }
            // int s=0;
            int win=k-ko;
            for(int i=0;i<=k;i++){
                ans+=f[k][i]*jiang(n-(ko+i),win-i)%mod;
                if(f[k][i]){
                    cout<<k<<' '<<i<<' '<<ko<<' '<<S<<' '<<f[k][i]<<'\n';
                }
                // s+=f[k][i]*jiang(n-(ko+i),win-i)%mod;
            }
            // cout<<s<<'\n';

        }
        ans=(ans%mod+mod)%mod;
        cout<<ans*fac[n-k]%mod<<'\n';
    }
}
/*
3 1
111
0 0 1
*/