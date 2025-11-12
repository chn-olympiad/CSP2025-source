#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k, s;
long long a[10010];
bool cmp(long long a, long long b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(i = 1; i <= n * m; i++) {
        cin >> a[i];
        if(i == 1) {
            k = a[i];
        }
    }
    sort(a + 1, a + n * m + 1, cmp);
    s = 0, i = 1, j = 1;
    while(s <= n * m) {
        s++;
        if(a[s] == k) {
            cout << j << " " << i << endl;
            return 0;
        }
        if(j % 2 == 1 && i == n) {
            j++;
            continue;
        }
        if(j % 2 == 0 && i == 1) {
            j++;
            continue;
        }
        if(j % 2 == 1 && i < n) {
            i++;
        }
        if(j % 2 == 0 && i > 1) {
            i--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
