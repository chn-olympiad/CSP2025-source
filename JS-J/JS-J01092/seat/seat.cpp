#include<bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("seat2.in", "r", stdin);
    freopen("seat2.out", "w", stdout);
    int n, m, wz;
    cin >> n >> m;
    for(int i=1; i<=n * m; i++)
    {
        cin >> a[i];
    }
    int t = a[1];
    sort(a+1, a+n*m+1, cmp);
    for(int i=1; i<=n*m; i++)
    {
        if(t == a[i]) wz = i;
    }
    int x, y;
    y = wz / m;
    if(wz > (y * m)) y+=1;
    if(y % 2 == 1)
    {
        if(wz % m == 0) x = m;
        else x = wz % m;
    }
    else
    {
        if(wz % m == 0) x = 1;
        else x = m - (wz % m) + 1;
    }
    cout << y << " " << x;
    return 0;
}
