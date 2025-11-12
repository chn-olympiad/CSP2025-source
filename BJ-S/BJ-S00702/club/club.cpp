/*
META:
BJ-S00702 2025/11/1
club.cpp T1
Status=Locked
Guess Score=100
E1 AC
E2 AC
E3 AC
E4 AC
E5 AC
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long a[100005][4];
long long tmp[100005];
long long n;
long long no[4][100005], c[4];
long long ans = 0;

long long fread() {
    long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

long long gfrom, gto1, gto2;
bool cmp(long long x, long long y) {
    return max(a[x][gto1], a[x][gto2]) - a[x][gfrom] > max(a[y][gto1], a[y][gto2]) - a[y][gfrom];
}

void procs(long long from, long long to1, long long to2) {
    gfrom = from;
    gto1 = to1;
    gto2 = to2;
    sort(no[from] + 1, no[from] + c[from] + 1, cmp);
    //printf("sort done\n");
    //for (long long i = 1; i <= c[from]; i++) cout << no[from][i] << " ";
    //cout << endl;
    for (long long i = 1; i <= c[from] - n / 2; i++) {
        long long x = no[from][i];
        ans += max(a[x][to1], a[x][to2]) - a[x][from];
        //printf("x=%d leave orig ans+=%d\n", x, max(a[x][to1], a[x][to2]) - a[x][from]);
    }
    return;
}

void solve() {
    c[1] = c[2] = c[3] = 0;
    ans = 0;
    cin >> n;
    bool zero2 = true, zero3 = true;
    for (long long i = 1; i <= n; i++) {
        a[i][1] = fread();
        a[i][2] = fread();
        a[i][3] = fread();
        if (a[i][2]) zero2 = false;
        if (a[i][3]) zero3 = false;
        if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
            ans += a[i][1];
            no[1][++c[1]] = i;
        }
        else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
            ans += a[i][2];
            no[2][++c[2]] = i;
        }
        else {
            ans += a[i][3];
            no[3][++c[3]] = i;
        }
    }
    if (zero2 && zero3) {
        for (long long i = 1; i <= n; i++) tmp[i] = a[i][1];
        sort(tmp + 1, tmp + n + 1);
        long long zans = 0;
        for (long long i = n; i >= n / 2; i--) zans += tmp[i];
        cout << zans << endl;
        return;
    }
    //printf("ans=%d\n", ans);
    if (c[1] * 2 > n) procs(1, 2, 3);
    else if (c[2] * 2 > n) procs(2, 1, 3);
    else if (c[3] * 2 > n) procs(3, 1, 2);
    cout << ans << endl;
    return;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    long long T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
