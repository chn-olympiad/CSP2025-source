#include <bits/stdc++.h>
using namespace std;
int arr[500007];
int cal[500007];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, a = 0, cnt = 0, rep; cin >> n >> k;
    cal[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        a = a ^ arr[i];
        cal[i + 1] = a;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) rep = arr[i];
            else        rep = arr[i] ^ arr[j];
            if (rep == k) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
