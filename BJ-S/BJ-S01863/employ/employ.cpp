#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int n2 = n;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if(a == 0) n2--;
    }
    if(n2 < m)
    {
        cout << 0;
        return 0;
    }
    long long ans = 1;
    for(int i = 1; i <= n2; i++)
    {
        ans = (ans * i) % 998244353;
    }
    cout << ans;
    return 0;
}
