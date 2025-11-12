#include <bits/stdc++.h>
using namespace std;
int n, m, a1, ind, c, r, a[105];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i = 0; i < n * m; i++)
    {
        cin>>a[i];
    }
    a1 = a[0];
    sort(a, a + n * m, cmp);
    for(int i = 0; i < n * m; i++)
    {
        if(a[i] == a1)
        {
            ind = i + 1;
        }
    }
    c = (ind - 1) / n + 1;
    if(c % 2 != 0)
    {
        r = (ind - 1) % n + 1;
    }
    else
    {
        r = n - ((ind - 1) % n);
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
