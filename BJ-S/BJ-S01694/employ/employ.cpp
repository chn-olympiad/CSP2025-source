#include <bits/stdc++.h>
using namespace std;

string s;
int ans = 1;
const int Q = 998244353;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    cin >> s;
    for(int i = 2; i <= n; ++i)
    {
        ans = ans * i % Q;
    }
    printf("%d\n", ans);
    return 0;
}
