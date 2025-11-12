#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Range {
    int l, r;
};
vector<Range> alls;
int n, k;
int a[500010], s[500010];
bool cmp(Range const& a, Range const& b) {
    return a.r < b.r;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] ^ a[i];
        if (a[i] == k) alls.push_back({i, i});
    }
    for (int l = 1; l <= n; l++)
        for (int r = l + 1; r <= n; r++)
            if ((s[r] ^ s[l - 1]) == k)
                alls.push_back({l, r});
    if (!alls.size()) {
        printf("0\n");
        return 0;
    }
    sort(alls.begin(), alls.end(), cmp);
    int lst = alls[0].r;
    ll cnt = 1;
    ll tot = alls.size();
    for (ll i = 1; i < tot; i++) {
        if (alls[i].l > lst) {
            lst = alls[i].r;
            cnt++;
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
