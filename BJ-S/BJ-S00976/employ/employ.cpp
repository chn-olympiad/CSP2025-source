#include <bits/stdc++.h>
using namespace std;
int c[505];
const int mod = 998244353;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    long long sum = 0, mul = 1;
    for (int i = 3; i <= n; i++)
    {
        long long mul = 1;
        for (int j = n; j >= n - i +1; j--)
        {
            mul *= j;
            mul %= mod;
        }
        sum += mul;
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}
