#include <bits/stdc++.h>
using namespace std;

long long arr[500005];
long long ans[500005];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    long long n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    long long ans2[n + 1];
    ans2[1] = arr[1];
    ans[1] = arr[1];
    for(int i = 2; i <= n; i++) {
        ans[i] = arr[i] ^ ans[i - 1];
        ans2[i] = arr[i] + ans2[i - 1];
    }

    long long maxn = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(ans[i] - ans[j] == k) {
                maxn = max(maxn, ans2[i] - ans2[j]);
            }
        }
    }

    cout << maxn << endl;

    return 0;
}
