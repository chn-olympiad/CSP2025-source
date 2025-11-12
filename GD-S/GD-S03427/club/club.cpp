# include <bits/stdc++.h>
# define maxn 100100
# define inf 0x3f3f3f3f
# define mem(a, val) memset(a, val, sizeof(a))
# define rep(i, j, k) for(int i = j; i <= k; ++i)
# define per(i, j, k) for(int i = j; i >= k; --i)
using namespace std;

int T, n, ans;
int a[maxn][3], d[maxn], Max[maxn];
int cnt[4];
vector<int> vec[3];

inline bool cmp(int x, int y) {return d[x] < d[y];}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = 0; vec[0].clear(); vec[1].clear(); vec[2].clear(); ans = 0;
        rep(i, 1, n) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) cnt[0]++, Max[i] = 0, d[i] = a[i][0] - max(a[i][1], a[i][2]), vec[0].push_back(i);
            else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) cnt[1]++, Max[i] = 1, d[i] = a[i][1] - max(a[i][0], a[i][2]), vec[1].push_back(i);
            else if(a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) cnt[2]++, Max[i] = 2, d[i] = a[i][2] - max(a[i][0], a[i][1]), vec[2].push_back(i);
            ans += a[i][Max[i]];
        }
        if(cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {cout << ans << '\n'; continue;}
        int id = 0, D = -n / 2;
        if(cnt[0] > n / 2) id = 0;
        else if(cnt[1] > n / 2) id = 1;
        else if(cnt[2] > n / 2) id = 2;
        D += cnt[id];
        sort(vec[id].begin(), vec[id].end(), cmp);
        rep(i, 0, D - 1) ans -= d[vec[id][i]];
        cout << ans << '\n'; 
    }
    return 0;
}