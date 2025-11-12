#include <bits/stdc++.h>
using namespace std;

int n, k, a[5000010], ans = 0;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            ans++;
        }
    }
    cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
