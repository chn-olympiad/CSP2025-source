#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 998244353;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if(n == 3)
    {
        if(a[0] + a[1] > a[2]) cout << 1;
        else cout << 0;
    }
    if(a[n - 1] = 1)
    {
        int s = 0;
        for(int i = 1; i < n; i++) s -= i;
        s += pow(2, n) - 1;
        cout << s - n;
    }

}
