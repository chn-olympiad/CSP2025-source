#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;

#define vi vector<int>
#define eb emplace_back
#define all(c) (c).begin(), (c).end()
#define req(i, l, r) for (int i = l, i##End = r; i < i##End; i = -~i)
#define rep(i, l, r) for (int i = l, i##End = r; i <= i##End; i = -~i)

template<typename T, typename U> void chkmx(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void chkmn(T &a, U b) { if (a > b) a = b; }

#define N 100005
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f

int n;
i64 ans;
int a[N][3];
vi ve[3];
    
void mslv() {
    scanf("%d", &n), ans = 0;
    rep(i, 1, n) scanf("%d%d%d", a[i], a[i] + 1, a[i] + 2);
    ve[0].clear(), ve[1].clear(), ve[2].clear();
    rep(i, 1, n) {
        int mx = 0;
        req(j, 0, 3) chkmx(mx, a[i][j]);
        req(j, 0, 3) if (mx == a[i][j]) ve[j].eb(i);
        ans += mx;
    }
    req(j, 0, 3) if (ve[j].size() > (n >> 1)) {
        vi vt;
        for (auto i : ve[j]) {
            sort(a[i], a[i] + 3);
            vt.eb(a[i][1] - a[i][2]);
        } sort(all(vt));
        req(i, 0, (int)ve[j].size() - (n >> 1)) {
            ans += vt.back();
            vt.pop_back();
        } break;
    } printf("%lld\n", ans);
}

void mprw() {}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    mprw();
    int _; scanf("%d", &_);
    while (_--) mslv();
    #ifdef JYR
    fprintf(stderr, "%.2lfMB ", abs(&Mbe - &Med) / 1048576.);
    fprintf(stderr, "%.0lfms ", clock() * 1000. / CLOCKS_PER_SEC);
    #endif
    return 0;
}