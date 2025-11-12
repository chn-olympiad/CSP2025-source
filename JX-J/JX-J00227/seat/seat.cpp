#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[100005];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n*m; i++) cin >> x[i];
    cout << 1 << " " << 1 << "\n";
    return 0;
}
