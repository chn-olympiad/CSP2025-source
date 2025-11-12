#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=501;
const int M=5005;
const ll P=998244353;
ll dp[N][N],f[M],a[M],n;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    f[1]=1;
    for(int i=2; i<=n; i++) {
        f[i]=f[i-1]*2+1;
        f[i]%=P;
    }
    for(int i=1; i<=n; i++) {
        dp[i][a[i]]=1;
        for(int j=a[i]+1; j<=500; j++) {
            for(int k=1; k<i; k++) {
                dp[i][j]+=dp[k][j-a[i]];
                dp[i][j]%=P;
            }
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++) {
        ll sum=0;
        for(int j=1; j<i; j++) {
            for(int k=1; k<=a[i]; k++) {
                sum+=dp[j][k];
                sum%=P;
            }
        }
        ans += f[i-1]-sum;
        ans %=P;
    }
    cout << ans%P;
    return 0;
}
