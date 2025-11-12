#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

int T, n, a[100010][4], maxn[100010], max2[100010], maxp[100010], max2p[100010], cnt[4], id[100010];
bool cmp(int x, int y) {
    return maxn[x] - max2[x] < maxn[y] - max2[y];
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios:: sync_with_stdio(0);
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        ll ans = 0;
        for (int i = 1, a, b, c; i <= n; i++) {
            cin >> a >> b >> c;
            maxn[i] = max({a, b, c}), id[i] = i;
            if (a == maxn[i]) {
                max2[i] = max(b, c), maxp[i] = 1;
                if (max2[i] == c) {
                    max2p[i] = b;
                } else {
                    max2p[i] = c;
                }
            } else if (b == maxn[i]) {
                max2[i] = max(a, c), maxp[i] = 2;
                if (max2[i] == a) {
                    max2p[i] = c;
                } else {
                    max2p[i] = a;#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

int T, n, a[100010][4], maxn[100010], max2[100010], maxp[100010], max2p[100010], cnt[4], id[100010];
bool cmp(int x, int y) {
    return maxn[x] - max2[x] < maxn[y] - max2[y];
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios:: sync_with_stdio(0);
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        ll ans = 0;
        for (int i = 1, a, b, c; i <= n; i++) {
            cin >> a >> b >> c;
            maxn[i] = max({a, b, c}), id[i] = i;
            if (a == maxn[i]) {
                max2[i] = max(b, c), maxp[i] = 1;
                if (max2[i] == c) {
                    max2p[i] = b;
                } else {
                    max2p[i] = c;
                }
            } else if (b == maxn[i]) {
                max2[i] = max(a, c), maxp[i] = 2;
                if (max2[i] == a) {
                    max2p[i] = c;
                } else {
                    max2p[i] = a;
                }
            } else if (c == maxn[i]) {
                max2[i] = max(a, b), maxp[i] = 3;
                if (max2[i] == a) {
                    max2p[i] = b;
                } else {
                    max2p[i] = a;
                }
            }
            ans += maxn[i];
        }
        for (int i = 1; i <= n; i++) {
            cnt[maxp[i]]++;
        }
        if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
            cout << ans << '\n';#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long

int T, n, a[100010][4], maxn[100010], max2[100010], maxp[100010], max2p[100010], cnt[4], id[100010];
bool cmp(int x, int y) {
    return maxn[x] - max2[x] < maxn[y] - max2[y];
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios:: sync_with_stdio(0);
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        ll ans = 0;
        for (int i = 1, a, b, c; i <= n; i++) {
            cin >> a >> b >> c;
            maxn[i] = max({a, b, c}), id[i] = i;
            if (a == maxn[i]) {
                max2[i] = max(b, c), maxp[i] = 1;
                if (max2[i] == c) {
                    max2p[i] = b;
                } else {
                    max2p[i] = c;
                }
            } else if (b == maxn[i]) {
                max2[i] = max(a, c), maxp[i] = 2;
                if (max2[i] == a) {
                    max2p[i] = c;
                } else {
                    max2p[i] = a;
                }
            } else if (c == maxn[i]) {
                max2[i] = max(a, b), maxp[i] = 3;
                if (max2[i] == a) {
                    max2p[i] = b;
                } else {
                    max2p[i] = a;
                }
            }
            ans += maxn[i];
        }
        for (int i = 1; i <= n; i++) {
            cnt[maxp[i]]++;
        }
        if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
            cout << ans << '\n';
            continue;
        }
        int wrong;
        for (int i = 1; i <= 3; i++) {
            if (cnt[i] > n / 2) {
                wrong = i;
                break;
            }
        }
        sort(id + 1, id + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            int p = id[i];
            if (maxp[p] != wrong) {
                continue;
            }
            cnt[max2p[p]]++, cnt[maxp[p]]--, ans = ans - maxn[p] + max2[p];
            if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
            continue;
        }
        int wrong;
        for (int i = 1; i <= 3; i++) {
            if (cnt[i] > n / 2) {
                wrong = i;
                break;
            }
        }
        sort(id + 1, id + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            int p = id[i];
            if (maxp[p] != wrong) {
                continue;
            }
            cnt[max2p[p]]++, cnt[maxp[p]]--, ans = ans - maxn[p] + max2[p];
            if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
                }
            } else if (c == maxn[i]) {
                max2[i] = max(a, b), maxp[i] = 3;
                if (max2[i] == a) {
                    max2p[i] = b;
                } else {
                    max2p[i] = a;
                }
            }
            ans += maxn[i];
        }
        for (int i = 1; i <= n; i++) {
            cnt[maxp[i]]++;
        }
        if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
            cout << ans << '\n';
            continue;
        }
        int wrong;
        for (int i = 1; i <= 3; i++) {
            if (cnt[i] > n / 2) {
                wrong = i;
                break;
            }
        }
        sort(id + 1, id + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            int p = id[i];
            if (maxp[p] != wrong) {
                continue;
            }
            cnt[max2p[p]]++, cnt[maxp[p]]--, ans = ans - maxn[p] + max2[p];
            if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}