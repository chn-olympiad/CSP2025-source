#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream cin("club.in");
    ofstream cout("club.out");
    int t;
    cin >> t;

    // A
    while (t--) {
        int n;
        cin >> n;
        vector<vector<long long>> a(n, vector<long long>(3));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        sort(a.begin(), a.end(), greater<>());
        long long ans = 0;
        int k = n / 2;
        for (int i = 0; i < k; i++) {
            ans += a[i][0];
        }
        cout << ans << '\n';
    }
}