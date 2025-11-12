#include<bits/stdc++.h>
using namespace std;
int m, n, a[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> m >> n;
    for(int i = 1;i <= m * n;i ++)
        cin >> a[i];
    int k = a[1], h;
    sort(a + 1, a + 1 + n * m);
    for(int i = m * n;i >= 1;i --)
    {
        if(a[i] == k)
        {
            h = m * n - i + 1;
            break;
        }
    }
    int i;
    i = h / n;
    if(h % n == 0)
    {
        cout << i << " " << n;
    }
    else
    {
        i ++;
        if(i % 2 == 0)
            cout << i << " "  << n - h % n;
        else
            cout << i << " "  << h % n;
    }
    return 0;
}
