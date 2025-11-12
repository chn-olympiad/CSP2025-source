#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int a, int b) {
    return  a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) 
        cin >> a[i];
    int k = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n * m; i++) 
        if (a[i] == k) ans = i;
    int a = (ans + n - 1) / n;
    if (a % 2 == 1) {
        cout << a << " " << (ans - 1) % n + 1;
        return 0;
    }
    else {
        cout << a << " " << n - ((ans - 1) % n + 1) + 1;
        return 0;
    }
    return 0;
}