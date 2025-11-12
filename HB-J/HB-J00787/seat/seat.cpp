#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;

    cin >> n >> m;

    int num = n * m;

    int a[105];

    cin >> a[1];
    int s = a[1], sum = 1;
    for (int i = 2; i <= num; ++i) {
        cin >> a[i];
        if (s < a[i]) sum++;
    }

    if (sum % n == 0) {
        if ((sum / n) % 2 == 0) cout << sum / n << " " << 1;
        else cout << sum / n << " " << n;
    }
    else {
        if ((sum / n) % 2 == 0) cout << sum / n + 1<< " " << n - sum % n - 1;
        else cout << sum / n  + 1 << " " << sum % n;
    }

    return 0;
}
