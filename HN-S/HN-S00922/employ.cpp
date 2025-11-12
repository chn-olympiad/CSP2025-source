#include<iostream>

using namespace std;

const int mod=998244353;

static inline void Mod(int &x){if(x>=mod)x-=mod;}

int n,m;
char a[505];
int c[505];

int dp[262144][20][20];

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>c[i];
    if(n==m){
        for(int i=0;i<n;++i)
            if(a[i]=='0'||c[i]==0){
                cout<<0<<endl;
                return 0;
            }
        int ans=1;
        for(int i=1;i<=n;++i)
            ans=1ll*ans*i%mod;
        cout<<ans<<endl;
        return 0;
    }
    int U=(1<<n)-1;
    dp[0][0][0]=1;
    for(int S=0;S<U;++S){
        int t=__builtin_popcountll(S);
        for(int i=0;i<=t;++i){
            for(int j=0;j<=n;++j){
                if(!dp[S][i][j])
                    continue;
                for(int x=0;x<n;++x){
                    if(!((S>>x)&1)){
                        if(i>=c[x]||a[t]=='0'){
                            Mod(dp[S|(1<<x)][i+1][j]+=dp[S][i][j]);
                        }else{
                            Mod(dp[S|(1<<x)][i][j+1]+=dp[S][i][j]);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;++i)
        for(int j=m;j<=n;++j)
            Mod(ans+=dp[U][i][j]);
    cout<<ans<<endl;
    return 0;
}