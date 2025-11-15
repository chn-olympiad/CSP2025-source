#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
ll C[505][505];
ll dp[2][502][502];
ll fact[505];
ll nCr(ll n, ll r){
    if(r>n)return 0;
    if(r<0){
        // cout<<"YES\n"; return 0;
    }
    return C[n][r];
}
ll nPr(ll n, ll r){
    if(r>n)return 0;
    if(r<0){
        // cout<<"Yes\n"; return 0;
    }
    return C[n][r]*fact[r]%MOD;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    char s[n+5];
    for(int i=1;i<=n;i++)cin>>s[i];
    ll a[n+5];
    for(int i=1;i<=n;i++)a[i]=s[i]-'0';
    ll c[n+5];
    for(int i=1;i<=n;i++)cin>>c[i];
    ll cnt[n+5];
    for(int i=0;i<=n+1;i++)cnt[i]=0;
    for(int i=1;i<=n;i++){
        cnt[c[i]]++;
    }
    ll psum[n+5]; psum[0]=cnt[0];
    for(int i=1;i<=n+1;i++){
        psum[i]=psum[i-1]+cnt[i]; 
    }
    ll zcnt=0;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        ll predp[n+2][n+2],ndp[n+2][n+2],faildp[n+2][n+2];
        for(int j=0;j<=n+1;j++){
            for(int k=0;k<=n+1;k++){
                predp[j][k]=dp[(i&1)^1][j][k];
            }
        }
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                dp[i&1][j][k]=0;
            }
        }
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++)ndp[j][k]=0,faildp[j][k]=0;
        }
        if(a[i]==0){
            zcnt++;
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    ndp[j][k]=(predp[j][k])%MOD;
                }
            }
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    ll cn=cnt[i-j];
                    for(int l=0;l<=cn;l++){
                        if(k-l<0)break;
                        dp[i&1][j][k-l]+=ndp[j][k]*nPr(k,l)%MOD*nCr(cn,l)%MOD; dp[i&1][j][k-l]%=MOD;
                    }
                }
            }
        }
        else{
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    // predp[j][k] contributes to ndp[j+1][k+1]
                    // predp[j][k] contributes to ndp[j][k]
                    // psum[i-j]-(i-1-zcnt-k)
                    ndp[j+1][k+1]=predp[j][k]; 
                    if(i-j-1>=0)faildp[j][k]=predp[j][k]*max(0LL,psum[i-j-1]-(i-1-zcnt-k))%MOD;
                }
            }
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    ll cn=cnt[i-j];
                    for(int l=0;l<=cn;l++){
                        if(k-l<0)break;
                        dp[i&1][j][k-l]+=faildp[j][k]*nPr(k,l)%MOD*nCr(cn,l)%MOD; dp[i&1][j][k-l]%=MOD;
                    }
                }
            }
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    dp[i&1][j][k]+=ndp[j][k]; dp[i&1][j][k]%=MOD;
                }
            }
        }
        // for(int j=0;j<=n;j++){
        //     for(int k=0;k<=n;k++){
        //         cout<<i<<" "<<j<<" "<<k<<' '<<dp[i&1][j][k]<<" "<<'\n';
        //     }
        // }
    }
    ll st=n&1;
    ll tot=0;
    for(int j=m;j<=n;j++){
        for(int k=0;k<=j;k++){
            tot+=dp[st][j][k]*max(0LL,nPr(psum[n]-psum[n-j],k))%MOD; tot%=MOD;
        }
    }
    tot*=fact[zcnt]; tot%=MOD;
    cout<<tot<<'\n';
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=2;i<=500;i++){
        for(int j=0;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1]; C[i][j]%=MOD;
        }
        C[i][i]=1;
    }
    fact[0]=1;
    for(int i=1;i<=500;i++){
        fact[i]=fact[i-1]*i; fact[i]%=MOD;
    }
    // cout<<nCr(6,3)<<'\n';    
    ll t=1;
    // cin>>t;
    while(t--)solve();   
}

/*
    g++ -std=c++2a -O2 employ.cpp -o employ && ./employ
*/