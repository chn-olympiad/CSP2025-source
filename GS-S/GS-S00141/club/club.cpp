#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, ans;
struct Member {
    ll d, mx, b;
}a[N];
vector<Member> p, q, r;

bool cmp(Member x, Member y) {return x.d < y.d;}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        p.clear(); q.clear(); r.clear();
        ans = 0;
        cin >> n;
        ll x, y, z;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> z;
            a[i].mx = max(x, max(y, z));
            if (a[i].mx == x) {
                a[i].b = 1, a[i].d = x - max(y, z);
                p.push_back(a[i]);
            }
            if (a[i].mx == y) {
                a[i].b = 2, a[i].d = y - max(x, z);
                q.push_back(a[i]);
            }
            if (a[i].mx == z) {
                a[i].b = 3, a[i].d = z - max(x, y);
                r.push_back(a[i]);
            }
            ans += a[i].mx;
        }
        int A = p.size(), B = q.size(), C = r.size();
        int cnt = 0;
        if (A > n/2) {
            sort(p.begin(), p.end(), cmp);
            while (A - cnt > n/2) ans -= p[cnt++].d;
        }
        if (B > n/2) {
            sort(q.begin(), q.end(), cmp);
            while (B - cnt > n/2) ans -= q[cnt++].d;
        }
        if (C > n/2) {
            sort(r.begin(), r.end(), cmp);
            while (C - cnt > n/2) ans -= r[cnt++].d;
        }
        cout << ans << '\n';
    }
    return 0;
}
