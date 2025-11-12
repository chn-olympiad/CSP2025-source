#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, K = 1 << 21;

int n, k;
int a[N], s[N];
int H[K];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        s[i] = s[i - 1] ^ a[i];
    }

    int l = 0, ans = 0;
    H[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(H[s[i] ^ k]) {
            ans++;
            for(; l < i; l++) {
                H[s[l]]--;
            }
        }

        H[s[i]]++;
    }

    cout << ans << '\n';
}