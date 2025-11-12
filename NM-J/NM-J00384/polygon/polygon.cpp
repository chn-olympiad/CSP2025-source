#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int a[N + 10], n;
int s = 0, cnt = 0;
int mian()
{
    freopen("polygon.in", "r", "stdin");
    freopen("polygon.out", "w", "stdout");
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for(int j = 1; j <= n; j++)
        {
            if(a[j] < a[j + 1]) swap(a[j], a[j + 1]);
        }
        s += a[i];
        if(s > a[1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
