#include <iostream>
#include <algorithm>
using namespace std;

const int md = 998244353;

int n, m;
char c[510];
int a[510];
int pw[510];

void init()
{
    pw[0] = 1;
    for (int i = 1; i <= 500; ++i)
        pw[i] = 1ll * pw[i - 1] * i % md;
}

void work1()
{
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cnt >= a[i])
        {
            cout << 0 << '\n';
            exit(0);
        }
        cnt += (c[i] == '0');
    }
    cout << 1 <<'\n';
    exit(0);
}

int p[10000];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    init();
    cin >> n >> m;
    cin >> (c + 1);
    for (int i = 1; i <= n; ++i)
        cin >>a[i];
    if (n == m)
        work1();
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    int ans = 0;
    do
    {
        int cnt = 0, usd = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (cnt >= a[p[i]] || c[i] == '0')
                ++cnt;
            else
                ++usd;
        }
        //cout << usd << '\n';
        if (usd >= m)
            ++ans;
    } while (next_permutation(p + 1, p + n + 1)) ;
    cout << ans << '\n';
    return 0;
}
