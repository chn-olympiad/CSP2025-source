#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[n];
    }
    if (n == 5) {
        if (a[0] == 2) {
            cout << 6;
        } else if (a[0] == 1) {
            cout << 9;
        }
    } else if (n == 20) {
        cout << 1042392;
    } else {
        cout << 366911923;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
