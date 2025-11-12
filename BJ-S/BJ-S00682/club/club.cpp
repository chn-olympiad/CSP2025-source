#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const bool DB = 0;
int n, T, a, b, c, cnt[4], ans, p[4];
int d[4][100005];

int main() {
    if (!DB) {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            int minn = min(a, min(b, c));
            int maxx = max(a, max(b, c));
            int ch = 0;
            if (a == maxx) ch = 1;
            else if (b == maxx) ch = 2;
            else ch = 3;
            //d[ch][i] = maxx - a - b - c + maxx + minn;
            //d[ch].push_back(maxx - a - b - c + maxx + minn);
            ++p[ch];
            d[ch][p[ch]] = maxx - a - b - c + maxx + minn;
            ++cnt[ch];
            ans += maxx;
        }
        //printf("%d %d %d\n", cnt[1], cnt[2], cnt[3]);
        int mx = max(cnt[1], max(cnt[2], cnt[3]));
        int t = 0;
        if (mx == cnt[1]) t = 1;
        else if (mx == cnt[2]) t = 2;
        else t = 3;
        //cout << t << endl;
        //printf("%d %d %d\n", p[1], p[2], p[3]);
        sort(d[t] + 1, d[t] + p[t] + 1);
        for (int i = 1; i <= cnt[t] - (n / 2); ++i) {
            ans -= d[t][i];
            //cout << d[t][i] << ' ';
        }
        //cout << endl;
        cout << ans << endl;
        a = 0; b = 0; c = 0;
        cnt[1] = 0; cnt[2] = 0; cnt[3] = 0;
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= p[i]; ++j) {
                d[i][j] = 0;
            }
        }
        p[1] = p[2] = p[3] = 0;
        ans = 0;
        //jideqingkong
    }
}
