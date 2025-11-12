# include <bits/stdc++.h>
using namespace std;
int n, m, a[1000001];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
        cin >> a[i];
    int c = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1;i <= n * m;i++) {
        if(c == a[i])
            c = i;
    }
    if(c == 1) {
        cout << 1 << " " << 1;
        return 0;
    }
    if(n == 1) {
        cout << c << " " << 1;
        return 0;
    }
    if(m == 1) {
        cout << 1 << " " << c;
        return 0;
    }
    if(n == 2) {
        if(c % 2 == 0 && (c/2) % 2 == 0)
            cout << c / 2 << " " << 1;
        else if(c % 2 == 0 && (c/2) % 2 == 1)
            cout << c / 2 << " " << 2;
        else if(c % 2 != 0 && (c/2) % 2 == 0)
            cout << (c + 1) / 2 << " " << 1;
        else if(c % 2 != 0 && (c/2) % 2 == 1)
            cout << (c + 1) / 2 << " " << 2;
        return 0;
    }
    if(m == 2) {
        if(c <= n)
            cout << 1 << " " << c;
        else {
            if(c % n == 0)
                cout << 2 << " " << 1;
            else
                cout << 2 << " " << n - c % n + 1;
        }
        return 0;
    }
    return 0;
}
