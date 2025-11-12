#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main(){

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int r = n * m;
    for(int i = 1; i <= r; i ++)  cin >> a[i];
    int f1 = 1;
    int f2 = 1;
    for(int i = 1; i <= r - 1; i ++)
    {
        if(a[i] != a[i + 1])  f1 = 0;
        if(a[i] - a[i + 1] != 1)  f2 = 0;
    }
    if(f1 == 1 || f2 == 1)
    {
        cout  << 1 << " " << 1;
        return 0;
    }
    int j = a[1];
    sort(a + 1, a + r + 1);
    int e;
    for(int i = r; i >= 1; i --)
    {
        if(a[i] == j)
        {
            e = r - i + 1;
            break;
        }
    }
    if(e % m != 0)
    {
        int g = e / m + 1;
        if(g % 2 == 0)
        {
            cout << g << " " << m - e % m + 1;
            return 0;
        }
        else
        {
            cout << g << " " << e % m;
            return 0;
        }
    }
    else
    {
        cout << e / m << " " << m;
        return 0;
    }

    return 0;
}
