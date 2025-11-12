#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 500005, M = (1 << 20) + 5;
const int inf = 0x3f3f3f3f;
int s[N], f[N], mx[M], n, k;
void work()
{
    cin >> n >> k;
    memset(mx, -0x3f, sizeof mx);
    mx[0] = 0;
    for (int i=1;i<=n;i++)
    {
        cin >> s[i];
        s[i] ^= s[i - 1];
        f[i] = max(f[i - 1], mx[s[i] ^ k] + 1);
        mx[s[i]] = max(mx[s[i]], f[i]);
    }
    cout << f[n];
    // 8:52 finished
}
int main()
{
    freopen("xor.in", "r", stdin);freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    //cin >> _T;
    while (_T --)
        work();
    return 0;
}