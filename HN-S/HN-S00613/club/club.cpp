#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

const int N = 1e5 + 5, INF = 1e9;

int n, a[N][3], pos[N], cnt[3], b[N];

void clear() {
    cnt[0] = cnt[1] = cnt[2] = 0;
    for(int i = 1; i <= n; i++) {
        b[i] = -INF;
    }
}

void solve() {
    cin >> n;
    clear();

    LL ans = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        
        int mx = max(a[i][0], max(a[i][1], a[i][2]));

        ans += mx;

        if(mx == a[i][0]) {
            pos[i] = 0;
        } else if(mx == a[i][1]) {
            pos[i] = 1;
        } else if(mx == a[i][2]) {
            pos[i] = 2;
        }
        cnt[pos[i]]++;
    }

    if(max(cnt[0], max(cnt[1], cnt[2])) <= n / 2) {
        cout << ans << '\n';
        return ;
    }

    int p = 0;

    if(cnt[1] > n / 2) {
        p = 1;
    }
    if(cnt[2] > n / 2) {
        p = 2;
    }

    for(int i = 1; i <= n; i++) {
        if(pos[i] == p) {
            b[i] = max(a[i][(p + 1) % 3], a[i][(p + 2) % 3]) - a[i][p];
        }
    }

    sort(b + 1, b + n + 1, greater<int>());

    for(int i = 1; i <= cnt[p] - n / 2; i++) {
        ans += b[i];
    }

    cout << ans << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int _T;

    cin >> _T;

    while(_T--) {
        solve();
    }
}