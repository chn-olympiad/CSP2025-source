#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> v(n*m);
    for (int &x : v) cin >> x;
    int a1 = v[0];
    int index;
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n*m; i++) {
        if (a1==v[i]) index=i+1;
    }
    int Q, R;
    Q = index / n;
    R = index % n;
    if (!R) cout << Q << " " << n;
    else {
        if (Q%2==0) cout << ++Q << " " << R;
        else cout << ++Q << " " << n-R+1;
    }
    return 0;
}
