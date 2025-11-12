#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    cin >> a[0];
    int s = a[0];
    for (int i = 1; i < n * m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int i;
    for (i = 0; a[i] != s; i++) {}
    cout << i / n + 1 << " ";
    if ((i / n) % 2 == 0)
    {
        cout << i % n + 1 << endl;
    }
    else
    {
        cout << n - i % n << endl;
    }
    return 0;
}