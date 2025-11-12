#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    int node, w;
}a[100005];

bool cmp(Node x, Node y)
{
    return x.w > y.w;
}

signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int m, n;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
        cin >> a[i].w;
        a[i].node = i;
    }
    sort (a + 1, a + n * m + 1, cmp);
    for (int i = 1;i <= m * n;i++) cout << a[i].w << " ";
    int t;
    for (int i = 1;i <= m * n;i++)
    {
        if (a[i].node == 1) t = i;
    }
    int t1 = t / n, t2 = t % n;
    if (t1 % 2 == 1) cout << t1 + 1 << " " << t2 << '\n';
    else cout << t1 + 1 << " " << n - t2 << '\n';
    return 0;
}
