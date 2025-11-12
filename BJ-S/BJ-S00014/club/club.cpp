#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int x = 0, w = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') w = -w; c = getchar(); }
    while (isdigit(c)) { x = (x << 3) + (x << 1) + c - 48; c = getchar(); }
    return x * w;
}

inline void write(int x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}

int T;
int n;
int a[100005][5];
int cnt[5];
vector<int> change[5];
int ans;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    T = read();

    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        change[1].clear();
        change[2].clear();
        change[3].clear();

        n = read();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++)
                a[i][j] = read();
            int s = a[i][1] + a[i][2] + a[i][3];
            int maxa = max(a[i][1], max(a[i][2], a[i][3]));
            int mina = min(a[i][1], min(a[i][2], a[i][3]));
            if (a[i][1] == maxa) {
                cnt[1]++;
                ans += a[i][1];
                change[1].push_back(2 * maxa - s + mina);
            } else if (a[i][2] == maxa) {
                cnt[2]++;
                ans += a[i][2];
                change[2].push_back(2 * maxa - s + mina);
            } else {
                cnt[3]++;
                ans += a[i][3];
                change[3].push_back(2 * maxa - s + mina);
            }
        }

        int maxc = max(cnt[1], max(cnt[2], cnt[3]));
        int t = maxc - n / 2, t2;

        if (cnt[1] == maxc)
            t2 = 1;
        else if (cnt[2] == maxc)
            t2 = 2;
        else
            t2 = 3;

        sort(change[t2].begin(), change[t2].end());

        for (int i = 0; i < t; i++)
            ans -= change[t2][i];

        write(ans);
        puts("");
    }

    return 0;
}
