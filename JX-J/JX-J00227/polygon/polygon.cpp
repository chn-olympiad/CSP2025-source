#include <bits/stdc++.h>
using namespace std;

int n, a[50000];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++) cnt = a[j] + cnt;
    cout << (cnt / n) + 1;
    return 0;
}
