#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
void read(T &x) {
    x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    x *= f;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + '0');
    else {
        print(x / 10);
        putchar(x % 10 + '0');
    }
}
const int N = 1e5 + 10;
struct node {
    int x, y, z, cnt;
} a[N];
int T, n, cnt[4], sum[4], ret[N], ans;
bool cmp(node q, node p) {
    int cnt1 = (!q.x) + (!q.y) + (!q.z);
    int cnt2 = (!p.x) + (!p.y) + (!p.z);
    if (q.cnt != p.cnt) return q.cnt > p.cnt;
    if (q.x != p.x) return q.x > p.x;
    if (q.y != p.y) return q.y > p.y;
    return q.z > p.z;
}
bool cmpa(node q, node p) {
    return q.x > p.x;
}
inline int choose(int i) {
    if (a[i].x == a[i].y && a[i].x == a[i].z) return 0;
    int mx = max(a[i].x, (a[i].y, a[i].z));
    if (mx == a[i].x) {/*
        if (a[i].x == a[i].y) return 4;
        if (a[i].x == a[i].z) return 5;*/
        return 1;
    }
    if (mx == a[i].y) {/*
        if (a[i].x == a[i].y) return 4;
        if (a[i].y == a[i].z) return 6;*/
        return 2;
    }
    /*
    if (a[i].x == a[i].z) return 5;
    if (a[i].y == a[i].z) return 6;*/
	return 3;
}
bool workA() {
    for (int i = 1; i <= n; ++i) {
        if (a[i].y || a[i].z) return false;
    }
    int ans = 0;
    for (int i = 1; (i << 1) <= n; ++i) ans += a[i].x;
    print(ans), putchar(10);
    return true;
}
void dfs(int cur, int s1, int s2, int s3, int sum) {
    if (cur > n) {
        ans = max(ans, sum);
        return ;
    }
    if ((s1 + 1 << 1) <= n) dfs(cur + 1, s1 + 1, s2, s3, sum + a[cur].x);
    if ((s2 + 1 << 1) <= n) dfs(cur + 1, s1, s2 + 1, s3, sum + a[cur].y);
    if ((s3 + 1 << 1) <= n) dfs(cur + 1, s1, s2, s3 + 1, sum + a[cur].z);
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    read(T);
    while (T--) {
        memset(a, 0, sizeof a);
        memset(cnt, 0, sizeof cnt);
        memset(ret, 0, sizeof ret);
        memset(sum, 0, sizeof sum);
        ans = 0;
        read(n);
        for (int i = 1; i <= n; ++i) {
            read(a[i].x), read(a[i].y), read(a[i].z);
            a[i].cnt = (!a[i].x) + (!a[i].y) + (!a[i].z);
        }
        if (workA()) continue;
        if (n <= 15) {
            dfs(1, 0, 0, 0, 0);
            print(ans), putchar(10);
            continue;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; ++i) {
            if (a[i].cnt == 3) continue;
            ret[i] = choose(i);
            ++cnt[ret[i]];
            sum[ret[i]] += (ret[i] == 1 ? a[i].x : (ret[i] == 2 ? a[i].y : a[i].z));
        }
        print(sum[1] + sum[2] + sum[3]), putchar(10);
    }
    return 0;
}
