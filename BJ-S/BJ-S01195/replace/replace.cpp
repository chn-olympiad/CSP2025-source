#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 1;

struct Node { string s1, s2; } s[MAXN];

int n, q;
Node t[MAXN];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) cin >> s[i].s1 >> s[i].s2;
    for (int i = 1; i <= q; i++) cin >> t[i].s1 >> t[i].s2;
    for (int i = 1; i <= n; i++) puts("0");
    return 0;
}

/*
瞎写的
期望得分：0
完成时间：3 h 30min

CSP-S2 最终完成时间：3h 30min
难度预估：绿黄蓝紫
*/
