#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, nm, num, c = 1, r = 1;
struct node
{
    int w, id;
}a[105];
bool cmp(node x, node y)
{
    return x.w > y.w;
}
void mv()
{
    if (c & 1)
    {
        if (r != n)
            r++;
        else
            c++;
    }
    else
    {
        if (r != 1)
            r--;
        else
            c++;
    }
}
signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m; nm = n * m;
    for (int i = 1; i <= nm; i++)
        cin >> a[i].w, a[i].id = i;
    sort(a + 1, a + nm + 1, cmp);
    for (int i = 1; i <= nm; i++)
        if (a[i].id == 1)
            num = i;
    for (int i = 1; i < num; i++)
        mv();
    cout << c << ' ' << r << endl;
    return 0;
}
