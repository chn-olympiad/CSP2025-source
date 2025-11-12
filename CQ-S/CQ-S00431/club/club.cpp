#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned ui;
typedef unsigned long long ull;

const int MAXN = 200010;

int tt = 1;

int n;
int buc[3];
struct miku
{
    ll v[3] = {0, 0, 0};
    int id = 0;
} a[MAXN];

void solve()
{
    scanf("%d", &n);
    ll ans = 0;
    buc[0] = buc[1] = buc[2] = 0;
    for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i].v[0], &a[i].v[1], &a[i].v[2]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            bool flg = true;
            for (int k = 0; k < 3; k++) flg &= (a[i].v[j] >= a[i].v[k]);
            if (flg) a[i].id = j;
        }
        ans += a[i].v[a[i].id], buc[a[i].id]++;
    }
    int maxx = 0, maxid = 0;
    for (int i = 0; i < 3; i++) if (buc[i] > maxx) maxx = buc[i], maxid = i;
    if (maxx * 2 <= n) {
        printf("%lld\n", ans);
        return;
    }
    int d = maxx - (n / 2), x = maxid;
    vector<ll> diff;
    for (int i = 1; i <= n; i++) if (a[i].id == x) {
        diff.push_back(min({a[i].v[x] - a[i].v[(x + 1) % 3], a[i].v[x] - a[i].v[(x + 2) % 3]}));
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < d; i++) ans -= diff[i];
    printf("%lld\n", ans);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &tt);
    while (tt--) solve();
    return 0;
}