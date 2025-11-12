#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    string s;
    int a[1000000];
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int sum = 1;
    for(int i = 1; i <= n; i++)
    {
        sum *= a[i];
    }
    cout << sum % 998244353;
}
