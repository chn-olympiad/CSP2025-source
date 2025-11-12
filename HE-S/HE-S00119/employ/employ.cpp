#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
long long sum = 1;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        sum *= i;
        sum = sum % 998244353;
    }
    cout << sum << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
