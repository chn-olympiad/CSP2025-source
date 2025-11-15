#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ifstream cin("club.in");
    ofstream cout("club.out");
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int arr[n][3], cnt[3], op[n], ans = 0;
        for (int i = 0; i < 3; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) cin >> arr[i][j];
            op[i] = max_element(arr[i], arr[i] + 3) - arr[i];
            cnt[op[i]]++;
            ans += arr[i][op[i]];
        }
        int mx = max_element(cnt, cnt + 3) - cnt;
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            sort(arr[i], arr[i] + 3);
            if (op[i] == mx) vec.emplace_back(arr[i][2] - arr[i][1]);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        while (cnt[mx] > n / 2) {
            ans -= vec.back();
            vec.pop_back();
            cnt[mx]--;
        }
        cout << ans << "\n";
    }
}