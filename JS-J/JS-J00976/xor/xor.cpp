#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, ans, a[500005], qz[500005];
bool cnt[2000005];
vector<int> vec;
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        qz[i] = (qz[i - 1] ^ a[i]);
//        cout << qz[i] << " ";
    }
//    cout << "\n";
    cnt[0] = 1;
    vec.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (cnt[qz[i] ^ k]) {
            ans++;
//            cout << i << "\n";
            for (int j = 0; j < vec.size(); j++) {
                cnt[vec[j]] = 0;
            }
            vec.clear();
            cnt[qz[i]] = 1;
            vec.push_back(qz[i]);
        } else {
            cnt[qz[i]] = 1;
            vec.push_back(qz[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
