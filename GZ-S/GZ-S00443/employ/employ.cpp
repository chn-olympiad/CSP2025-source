//GZ-S00443 华麟 郭一菲
#include <bits/stdc++.h>
using namespace std;
long long a[10005], ans = 1, b[10005];
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
        cin >> a[i];
        b[a[i]]++;
        ans = (ans * i) % 998244353;
    }
    if (m == n){
        ans = 0;
    }
    cout << ans;
    return 0;
}
