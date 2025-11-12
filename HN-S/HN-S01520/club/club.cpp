#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 205;

int n, a[N], b[N], c[N], cnt[3], tot, dp[M][M][M], ans, DP[N];
bool f[N];

struct tp{
    int x, id1, id2, id;
} s[N * 2];

bool cmp(const tp &i, const tp &j){
    return i.x < j.x;
}

void solve_200(){
    for(int i = 0; i <= 200; i++){
        for(int j = 0; j <= 200; j++){
            for(int k = 0; k <= 200; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for(int i = 0; i <= n / 2; i++){
        for(int j = 0; j <= n / 2; j++){
            for(int k = 0; k <= min(n / 2, n - i - j); k++){
                if(i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i + j + k]);
                if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + b[i + j + k]);
                if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + c[i + j + k]);
            }
        }
    }
    ans = 0;
    for(int i = 0; i <= n / 2; i++){
        for(int j = 0; j <= n / 2; j++){
            int k = n - i - j;
            if(k <= n / 2){
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << '\n';
}

void solve_f1(){
    sort(a + 1, a + n + 1);
    ans = 0;
    for(int i = n; i >= n / 2; i--){
        ans += a[i];
    }
    cout << ans << '\n';
}

void solve(){
    cin >> n;
    bool f1 = 1, f2 = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
        f[i] = 0;
        f1 &= (b[i] == 0 && c[i] == 0);
    }
    if(n <= 200){
        solve_200();
        return;
    }
    if(f1){
        solve_f1();
        return;
    }
    cnt[0] = cnt[1] = cnt[2] = 0;
    int ans = 0;
    tot = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > b[i] && a[i] > c[i]){
            cnt[0]++;
            ans += a[i];
            s[++tot] = {a[i] - b[i], 0, 1, i};
            s[++tot] = {a[i] - c[i], 0, 2, i};
        }
        else if(b[i] > a[i] && b[i] > c[i]){
            cnt[1]++;
            ans += b[i];
            s[++tot] = {b[i] - a[i], 1, 0, i};
            s[++tot] = {b[i] - c[i], 1, 2, i};
        }else{
            cnt[2]++;
            ans += c[i];
            s[++tot] = {c[i] - a[i], 2, 0, i};
            s[++tot] = {c[i] - b[i], 2, 1, i};
        }
    }
    if(max({cnt[0], cnt[1], cnt[2]}) <= n / 2){
        cout << ans << '\n';
        return;
    }
    sort(s + 1, s + tot + 1, cmp);
    for(int j = 1; j <= tot; j++){
        int id1 = s[j].id1, id2 = s[j].id2, x = s[j].x, i = s[j].id;
        if(cnt[id1] > n / 2 && !f[i]){
            if(cnt[id2] < n / 2){
                f[i] = 1;
                cnt[id1]--;
                cnt[id2]++;
                ///cout << (id1 == 0 ? a[i] : (id1 == 1 ? b[i] : c[i])) << ' ';
                ///cout << (id2 == 0 ? a[i] : (id2 == 1 ? b[i] : c[i])) << ' ';
                ///cout << i << ' ' << id1 << ' ' << id2 << ' ' << cnt[id1] << ' ' << cnt[id2] << ' ';
                ///cout << ans << ' ';
                ans -= (id1 == 0 ? a[i] : (id1 == 1 ? b[i] : c[i]));
                ans += (id2 == 0 ? a[i] : (id2 == 1 ? b[i] : c[i]));
                ///cout << ans << '\n';
            }
        }
    }
    ///cout << n / 2 << ' ' << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
    cout << ans << '\n';
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
