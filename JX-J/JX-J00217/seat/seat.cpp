#include <bits/stdc++.h>
using namespace std;

int n, m, g, pos = 0;
int s[15];
bool cmp(int x, int y) {return x > y;}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> s[i];
    g = s[1];
    sort(s + 1, s + n * m + 1, cmp);
    int r = 1, c = 1, pos = 1;
    for (int i = 1; i <= n * m; i++) {
        if (s[i] == g) {
            cout << c << ' ' << r << endl;
            return 0;
        }
        r += pos;
        if (r == n + 1) {
            c++;
            r = n;
            pos = -1;
        } 
        if (r == 0) {
            c++;
            r = 1;
            pos = 1;
        }
    } 
    
    
    return 0;
}