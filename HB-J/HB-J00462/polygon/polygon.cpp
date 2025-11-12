//CCF shi zhi hui chu huang ti le ma
//xiang jin mi huo xing wei da shang
//freopen("polygon.in", "r", stdin);
//rks 15.54
//feropen
//frepoen
//orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz qcywyxchtlyszzwzyz
//int mian
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int a[5001], dp[5002];
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = a[i] + 1; j <= 5001; j++)ans = (ans + dp[j]) % mod;
        for(int j = 5001; j >= 5001 - a[i]; j--)dp[5001] = (dp[5001] + dp[j]) % mod;
        for(int j = 5000; j >= a[i]; j--)dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    }
    cout << ans;
    return 0;
}
