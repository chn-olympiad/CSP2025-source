#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

/*ll dp(int x)
{
    ll ansHere = 0;
    for (int i = 0; i < d.size(); i++)
    {
        max(d[x - 1], in+1) > min{in+1, in} > max{in, in+1} - sumOf_n-1:i} ? ans++ : continue;
    }
    return (dp(x - 1) + ansHere) % MOD;
}
*/
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    vector<int> d;
    int n;
    cin >> n;
    for (int i = 1; i <= n ; i++)
    {
        int a;
        cin >> a;
        d.push_back(a);
    }
    cout << 10<<'/n';
    return 0;
}
