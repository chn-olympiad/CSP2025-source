#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e5 + 5;
int n, cnt[3], ans;
typedef pair<int, int> PII;
#define x first
#define y second
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = cnt[0] = cnt[1] = cnt[2] = 0;
        priority_queue<int> q[3];
        for(int i = 1, x, y, z; i <= n; i++) {
            vector<PII> v(3);
            cin >> x >> y >> z;
            v[0] = {x, 0}, v[1] = {y, 1}, v[2] = {z, 2};
            sort(v.begin(), v.end(), greater<PII>());
            cnt[v[0].y]++, ans += v[0].x;
            q[v[0].y].push(v[1].x - v[0].x);
        }
        if(cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
            cout << ans << '\n';
            continue;
        }
        int k = 4;
        if(cnt[0] > n / 2) k = 0;
        else if(cnt[1] > n / 2) k = 1;
        else k = 2;
        while(cnt[k] > n / 2) {
            ans += q[k].top(), q[k].pop(), cnt[k]--;
        }
        cout << ans << '\n';
    }
    return 0;
}