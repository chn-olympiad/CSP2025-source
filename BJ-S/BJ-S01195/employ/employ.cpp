#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e2 + 1;
const int MOD = 998244353;

int n, m, c[MAXN], cnt;
string s;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    cin >> s;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) cnt += a[i] != 0;
    if (!cnt) printf("%d", n * (n + 1) / 2);
    return 0;
}

/*
拿个部分分，反正是乱写的
期望得分：5
完成时间：1h 45min
*/
