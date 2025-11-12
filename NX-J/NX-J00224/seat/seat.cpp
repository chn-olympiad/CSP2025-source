#include<bits/stdc++.h>
using namespace std;
bool cmp (int x, int y)
{
    return x > y;
}
int a[105];
int b[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int w = n *m;
    for (int i = 1;i <= w;i++)
    {
        cin >> a[i];
    }
    int r = a[1];
    sort (a + 1, a + w + 1, cmp);
    int u;
    for (int i = 1;i <= w;i++)
    {
        if (a[i] == r) u = i;
    }
    int l = u / n;
    int h = u % n;
    if (h != 0) l ++;
    if (l % 2 == 0)
    {   if (h == 0)h = n;
        cout << l << " " << n +1 - h;
    }
    else
    {   if (h == 0)h = n;
        cout << l << " " << h;
    }
    return 0;
}
