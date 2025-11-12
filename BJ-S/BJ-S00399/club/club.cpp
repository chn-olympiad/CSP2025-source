#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int T, n, a[maxn], b[maxn], c[maxn], dp[105][105][105];

inline int r() {
    int x=0, f=1;char ch=getchar();
    while (ch < '0' || ch > '9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch >= '0' && ch <= '9') {x = x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int max(int x, int y) {return x > y ? x : y;}

void point50()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1;i <= n;i++) {
        for (int w1 = n / 2;w1 >= 0;w1--) {
            for (int w2 = n / 2;w2 >= 0;w2--) {
                for (int w3 = n / 2;w3 >= 0;w3--) {
                    int res = -1;
                    if (w1 != 0) res = max(res, dp[w1-1][w2][w3] + a[i]);
                    if (w2 != 0) res = max(res, dp[w1][w2-1][w3] + b[i]);
                    if (w3 != 0) res = max(res, dp[w1][w2][w3-1] + c[i]);
                    dp[w1][w2][w3] = res;
                }
            }
        }
    }
    cout << dp[n/2][n/2][n/2] << '\n';
}

bool cmp(int x, int y) {return x > y;}
void pointA()
{
    sort(a + 1, a + n + 1, cmp); int ans = 0;
    for (int i = 1;i <= n/2;i++) {
        ans += a[i];
    }
    cout << ans << '\n';
}




struct Query {
    int a, b, c, plsa, plsb, plsc, maxx;
}q[maxn];

bool cmpa(Query x, Query y) {
    return x.plsa > y.plsa;
}
bool cmpb(Query x, Query y) {
    return x.plsb > y.plsb;
}
bool cmpc(Query x, Query y) {
    return x.plsc > y.plsc;
}

void solve()
{
    int numa = 0, numb = 0, numc = 0, sum = 0;
    for (int i = 1;i <= n;i++) {
        q[i].a = a[i], q[i].b = b[i], q[i].c = c[i];
        q[i].plsa = max(b[i] - a[i], c[i] - a[i]);
        q[i].plsb = max(c[i] - b[i], a[i] - b[i]);
        q[i].plsc = max(a[i] - c[i], b[i] - c[i]);
        q[i].maxx = max(max(a[i], b[i]), c[i]);
        if (a[i] >= b[i] && a[i] >= c[i]) {numa++; sum += a[i];}
        else if (b[i] >= a[i] && b[i] >= c[i]) {numb++; sum += b[i];}
        else {numc++; sum += c[i];}
    }
    if (numa > n / 2) {
        sort(q +1, q + n +1, cmpa);
        int cnt = 0;
        for (int i = 1;;i++) {
            if (cnt >= numa - n / 2) break;
            if (q[i].a != q[i].maxx) continue;
            cnt++;
            sum += q[i].plsa;
        }
    }
    else if (numb > n / 2) {
        sort(q +1, q + n +1, cmpb);
        int cnt = 0;
        for (int i = 1;;i++) {
            if (cnt >= numb - n / 2) break;
            if (q[i].b != q[i].maxx) continue;
            cnt++;
            sum += q[i].plsb;
        }
    }
    else {
        sort(q +1, q + n +1, cmpc);
        int cnt = 0;
        for (int i = 1;;i++) {
            if (cnt >= numc - n / 2) break;
            if (q[i].c != q[i].maxx) continue;
            cnt++;
            sum += q[i].plsc;
        }
    }

    cout << sum << '\n';
}


signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    T = r();
    while (T--) {
        n = r();
        bool ptsA = 1;
        for (int i = 1;i <= n;i++) {
            a[i] = r(), b[i] = r(), c[i] = r();
            ptsA &= (b[i] == 0 and c[i] == 0);
        }
        if (ptsA) {pointA(); continue;}
        else if (n <= 200) {point50(); continue;}
        solve();
    }
    return 0;
}

