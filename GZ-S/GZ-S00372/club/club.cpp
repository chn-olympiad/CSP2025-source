//GZ-S00372 遵义市第四中学 翁铭卓
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 10;

int n, sum = 0, cnt0 = 0;
int a[N][5];
priority_queue<int> q;

template<typename T> void write(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

void dfs(int u, int cnt1, int cnt2, int cnt3, int w)
{
    if (u > n)
    {
        sum = max(sum, w);
        return;
    }
    if (cnt1 + 1 <= n / 2)
        dfs(u + 1, cnt1 + 1, cnt2, cnt3, w + a[u][1]);
    if (cnt2 + 1 <= n / 2)
        dfs(u + 1, cnt1, cnt2 + 1, cnt3, w + a[u][2]);
    if (cnt3 + 1 <= n / 2)
        dfs(u + 1, cnt1, cnt2, cnt3 + 1, w + a[u][3]);
    return;
}

template<typename T> void read(T &qwq)
{
    T x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    qwq = x * f;
    return;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    read(T);

    while (T -- )
    {
        while (q.size())
            q.pop();
        sum = 0, cnt0 = 0;
        read(n);

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= 3; j ++)
            {
                if (a[i][j] == 0)
                    cnt0 ++;
                read(a[i][j]);
            }

        if (cnt0 >= n)
        {
            for (int i = 1; i <= n; i ++ )
                q.push(a[i][1]);
            for (int i = 1; i <= n / 2; i ++ )
                sum += q.top(), q.pop();
            write(sum), puts("");
            continue;
        }

        dfs(1, 0, 0, 0, 0);
        write(sum), puts("");
    }

    return 0;
}
