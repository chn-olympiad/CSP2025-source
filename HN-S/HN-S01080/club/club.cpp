#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 3;
int T, n, a[N], b[N], c[N], d[N], cnt[4];
bool vis[N];
struct Node {
    int x, y, z;
} p[M];

inline int Get(int x, int y) {
    if(x < 0 && y < 0) return max(x, y);

    if(x < 0) return x;
    if(y < 0) return y;

    return -1e18;
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while(T --) {
        cin >> n;
        for(int i = 1 ; i <= n ; ++ i) {
            cin >> a[i] >> b[i] >> c[i];

            p[i] = {a[i], i, 1}, p[i + n] = {b[i], i, 2}, p[i + n * 2] = {c[i], i, 3};
        }

        sort(p + 1, p + 1 + n * 3, [&](Node a, Node b) {
            return a.x > b.x;
        });

        int ans = 0;

        for(int i = 1 ; i <= n * 3 ; ++ i) {
            int x = p[i].x, pos = p[i].y, num = p[i].z;

            if(vis[pos]) continue ;
            ans += x;
            ++ cnt[num];
            vis[pos] = true;
        }

        int id = 0;

        for(int i = 1 ; i <= 3 ; ++ i)
            if(cnt[i] > n / 2) {
                id = i;

                break ;
            }

        // cerr << ans << '\n';

        // cerr << "id:" << id << '\n';

        fill(vis + 1, vis + 1 + n, false);

        int tot = 0, res = ans;

        for(int i = 1 ; i <= n * 3 ; ++ i) {
            int x = p[i].x, pos = p[i].y, num = p[i].z;

            if(vis[pos]) continue ;
            vis[pos] = true;

            if(num == id) {
                if(id == 1) d[++ tot] = max(b[pos] - x, c[pos] - x);
                if(id == 2) d[++ tot] = max(a[pos] - x, c[pos] - x);
                if(id == 3) d[++ tot] = max(a[pos] - x, b[pos] - x);

                // cerr << "ans:" << pos << ' ' << d[tot] << '\n';
            }
        }

        sort(d + 1, d + 1 + tot, greater<int>());

        for(int i = 1 ; i <= cnt[id] - n / 2 ; ++ i)
            res += d[i];//, cerr << d[i] << ' ';
        // cerr << '\n';

        cout << res << '\n';

        fill(d + 1, d + 1 + n, 0ll);
        fill(cnt + 1, cnt + 4, 0ll);
        fill(vis + 1, vis + 1 + n, false);
    }

    return 0;
}

/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/