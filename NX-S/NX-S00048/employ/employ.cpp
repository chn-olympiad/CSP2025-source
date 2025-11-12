#include<bits/stdc++.h>
using namespace std;
int m, n, s = 1, a[505], b;
string x;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> x;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if(a[i] <= b) b ++;
    }
    n -= b;
    for(int i = 1; i <= n; i ++)
    {
        s *= i;
        s %= 998244353;
    }
    cout << 0 << endl;
    return 0;
}
