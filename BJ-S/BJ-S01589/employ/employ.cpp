#include <bits/stdc++.h>
using namespace std;
#define For(i, x, y) for (int i = x; i <= y; i++)
#define foR(i, x, y) for (int i = x, i >= y; i--)
#define vector basic_string
typedef pair<int, int> pii;
const int N = 505;
int n, m, c[N], p[N], ans;
char s[N];

bool check()
{
    int cnt = 0;
    For (i, 1, n)
    {
        if (s[i] == '0')
            cnt++;
        else if (cnt >= c[p[i]])
            cnt++;
    }
    return n - cnt >= m;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    scanf("%s", s + 1);
    For (i, 1, n)
        scanf("%d", c + i), p[i] = i;
    check();
    do
    {
        ans += check();
    } while (next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
    return 0;
}