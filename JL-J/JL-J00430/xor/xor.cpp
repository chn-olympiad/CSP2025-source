#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define per(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define PII pair<int, int>

const int N = 500010, M = 1048600;
int n, k, a[N], ans;
int s[N], p[N], dp[N];
PII t[N];
vector<int> e[M];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    rep(i, 1, n)
        scanf("%d", &a[i]);
    rep(i, 1, n) {
        s[i] = s[i - 1] ^ a[i];
        e[s[i]].push_back(i);
    }
    rep(i, 1, n) {
        int x = k ^ s[i - 1];
        int sz = (int) e[x].size();
        if(sz == 0) {
            p[i] = n + 1;
            continue;
        }
        auto it = lower_bound(e[x].begin(), e[x].end(), i);
        if(it == e[x].end()) {
            p[i] = n + 1;
            continue;
        }
        p[i] = *it;
    }
    rep(i, 1, n)
        t[i] = {p[i], i};
    sort(t + 1, t + n + 1);
    rep(i, 1, n) {
        dp[t[i].first] = max(dp[t[i].second - 1] + 1, dp[t[i].first]);
        rep(j, t[i].second, t[i + 1].second)
            dp[j] = max(dp[j - 1], dp[j]);
    }
    rep(i, 1, n)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
}
