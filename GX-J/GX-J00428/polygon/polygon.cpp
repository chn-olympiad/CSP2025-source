#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n;
    cin >> n;

    int m = 0;
    int arr[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans[n + 1];
    ans[1] = arr[1];
    for(int i = 2; i <= n; i++) {
        ans[i] = arr[i] + ans[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int maxn = -1;
            for(int k = i; k <= j; k++) {
                maxn = max(arr[i], maxn);
            }

            if(ans[i] - ans[j] > 2 * maxn) {
                m++;
            }
        }
    }

    cout << m << endl;

    return 0;
}
