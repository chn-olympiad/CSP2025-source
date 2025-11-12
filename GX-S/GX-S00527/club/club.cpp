#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for(int i = s, rep##i = t; i <= rep##i; ++i)
#define per(i, t, s) for(int i = t, per##i = s; i >= per##i; --i)
#define gc getchar
#define pb push_back
typedef long long ll;

int rd() {
    int x = 0, f = 0;
    char ch = gc();
    while(!isdigit(ch)) {if(ch == '-') f = 1; ch = gc();}
    while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
    return f ? -x : x;
}

constexpr int N = 100005;
int a[N][5], n;

int getyou(int i) {
    int x = max({a[i][1], a[i][2], a[i][3]});
    if(x == a[i][1]) return 1;
    if(x == a[i][2]) return 2;
    return 3;
}

int S[5], ans;
void solve() {
    n = rd();
    rep(i, 1, n) a[i][1] = rd(), a[i][2] = rd(), a[i][3] = rd();

    S[1] = S[2] = S[3] = ans = 0;
    rep(i, 1, n) {
        int o = getyou(i);
        ans += a[i][o];
        S[o]++;
    }
    if(S[1] <= n / 2 && S[2] <= n / 2 && S[3] <= n / 2) return printf("%d\n", ans), void();
        vector<int> V;
        int p = 0;
        rep(i, 1, 3) if(S[i] > n / 2) p = i;
        rep(i, 1, n) {
            if(getyou(i) == p) {
                int tmp = 2e9;
                rep(j, 1, 3) if(j ^ p) tmp = min(tmp, a[i][p] - a[i][j]);
                V.pb(tmp);
            }
        }
        sort(V.begin(), V.end());
        rep(i, 0, S[p] - n / 2 - 1) ans -= V[i];
        printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    rep(T, 1, rd()) solve();
    return 0;
}
