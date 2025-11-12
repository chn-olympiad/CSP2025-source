#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int tot = n * m;
    int pm = 1;
    for (int i = 1;i <= tot;i++)
    {
        cin >> a[i];
        if (a[i] > a[1]) pm++;
    }
    int x = pm / m,y = pm % m;
    if (y != 0) x++;
    if (x % 2 == 0) y = n - y + 1;
    if (y == 0) cout << x << " " << n << endl;
    else cout << x << " " << y << endl;
}
