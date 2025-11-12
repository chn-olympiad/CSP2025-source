#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n, m, a[505], bar[505], xian[505], ans=1, dp[1<<18][19];
string s;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> s;
    for(int i=1; i<=n; i++){
        int x;cin >> x;
        bar[x]++;a[i-1]=x;
    }
    if(m==1){
        for(int i=0; i<n; i++){
            if(s[i]=='0')xian[n]++;
            else xian[i]++;
        }int hav=0, al=1;
        for(int i=0; i<=n; i++){
            hav+=bar[i];
            while(xian[i]--){
                ans=1ll*ans*hav%mod;
                hav--;
            }
        }
        for(int i=1; i<=n; i++)al=1ll*al*i%mod;
        cout << (al-ans+mod)%mod << '\n';
        return 0;
    }
    if(m==n){
        int tg=1;
        for(int i=0; i<n; i++)if(s[i]=='0')tg=0;
        if(!tg||bar[0])cout << 0 << '\n';
        else{
            for(int i=1; i<=n; i++)ans=1ll*ans*i%mod;
            cout << ans << '\n';            
        }
        return 0;
    }dp[0][0]=1;
    for(int i=0; i<(1<<n)-1; i++){
        for(int j=0; j<n; j++){
            if(!dp[i][j])continue;
            int now=__builtin_popcount(i);
            for(int t=0; t<n; t++){
                if(i&(1<<t))continue;
                if(s[now]=='0'||j>=a[t])dp[i|(1<<t)][j+1]=(dp[i|(1<<t)][j+1]+dp[i][j])%mod;
                else dp[i|(1<<t)][j]=(dp[i|(1<<t)][j]+dp[i][j])%mod;
            }
        }
    }ans=0;
    for(int i=0; i<=n-m; i++)ans=(ans+dp[(1<<n)-1][i])%mod;
    cout << ans;
    return 0;
}