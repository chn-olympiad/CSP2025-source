#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 998244353;
int n;
vector<int> a;
int cnt = 0;
void dfs(int i, int maxx, int sum){
    if (i == n){
        if (sum > 2 * maxx){
            cnt++;
        }
        return;
    }
    dfs(i + 1, a[i], sum + a[i]);
    dfs(i + 1, maxx, sum);
}

signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        sum += x;
        a.push_back(x);
    }

    if (sum == n){
        cout << n - 2 << endl;
        return 0;
    }

    sort(a.begin(), a.end());

    if (n == 3){
        if (a[0] + a[1] <= a[2]){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
        return 0;
    }

    if (n <= 20){
        dfs(0, 0, 0);
        cout << cnt << endl;
        return 0;
    }
    
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = sum; j >= a[i - 1]; --j){
            dp[j] = dp[j] + dp[j - a[i - 1]];
            dp[j] %= MOD;
        }
        for (int j = 2 * a[i - 1] + 1; j <= sum; ++j){
            ans += dp[j];
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}