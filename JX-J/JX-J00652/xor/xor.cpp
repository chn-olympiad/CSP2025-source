#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, k;
int arr[N];
int sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "W", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] ^ arr[i];
    }

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= i) cout << (sum[j] ^ sum[i - 1]) << " ";
            else cout << "x ";
        }
        cout << '\n';
    }
    */

    int l = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = l; j <= i; j++) {
            int x = (sum[i] ^ sum[j - 1]);
            if (x == k) {
                ans++;
                l = i + 1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
