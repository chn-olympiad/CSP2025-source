#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    typedef long long ll;
    const int mod=998244353;
    int n,m;
    string s;
    int c[505];
    ll f[2][19][300005];
    void solve(){
        cin>>n>>m;
        cin>>s;s=" "+s;
        for(int i=1;i<=n;i++) cin>>c[i];
        f[0][0][0]=1;
        for(int i=0;i<n;i++){
            int op=i&1;
            memset(f[op^1],0,sizeof(f[op^1]));
            for(int k=0;k<(1<<n);k++){
                int cnt=0;
                for(int j=0;j<n;j++) if((k>>j)&1) cnt++;
                if(cnt!=i) continue;
                for(int j=0;j<=i;j++){
                    if(f[op][j][k]==0) continue;
                    for(int o=1;o<=n;o++){
                        if((k>>(o-1))&1) continue;
                        int to=(k|(1<<(o-1)));
                        if(s[i+1]=='0' || c[o]<=j){
                            f[op^1][j+1][to]=(f[op^1][j+1][to]+f[op][j][k])%mod;
                        }
                        else{
                            f[op^1][j][to]=(f[op^1][j][to]+f[op][j][k])%mod;
                        }

                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<=n-m;i++) ans=(ans+f[n&1][i][(1<<n)-1])%mod;
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    mycode::solve();
    return 0;  
}