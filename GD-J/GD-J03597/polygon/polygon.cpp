#include<bits/stdc++.h>
using namespace std;

bool ed;
const int maxn = 10005;
const int mod = 998244353;
int mx, a[maxn], dp[2][maxn], n, ans;
bool st;

void Add(int &x, int y){
    ((x += y) >= mod) && (x -= mod);
}

int ad(int x, int y){
    return x + y < mod ? x + y : x + y - mod;
}

signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int now = 0;
    mx = a[n];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        now ^= 1;
        memset(dp[now], 0, sizeof(dp[now]));
        for(int j = 0; j <= mx * 2; j++){
            int x = dp[now ^ 1][j];
            Add(dp[now][j], x);
            if(j + a[i] <= mx){
                Add(dp[now][j + a[i]], x);
            }
        }
        for(int j = 0; j <= a[i]; j++){
            Add(ans, dp[now ^ 1][j]);
        }
    }
    int sum = 1;
    for(int i = 1; i <= n; i++){
        sum = 2ll * sum % mod;
    }
    sum--;
    cout << (sum - ans + mod) % mod;

    return 0;
}