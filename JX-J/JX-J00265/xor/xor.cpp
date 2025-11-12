#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int a[500005] = { 0 };
    int n, k, awa = -1, num = 0, j = 0;
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for (int i = 0 ; i <= n ; i++) {
        if (awa == -1) {
            awa = a[i];
            j = i;
        }
        else if (awa == k) {
            i--;
            num++;
            awa = -1;
            cout << "[" << j << "-" << i << "]\n";
        }
        else {
            awa = awa xor a[i];
        }
        //cout << i << "-" << awa << "\n";
    }
    cout << num;
    //
    return 0;
}
