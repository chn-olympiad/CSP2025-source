#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, a[100010][5];
vector <int> v;
bool cmp(int a, int b) {
    return a > b;
}
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; ++ i) {
        cin >> n;
        for (int j = 0; j < n; ++ j) {
            for (int k = 0; k < 3; ++ k) {
                cin >> a[j][k];
                if (k == 0) v.push_back(a[j][k]);
            }
        }
        sort(v.begin(), v.end(), cmp);
        int ans = 0;
        for (int i = 0; i < v.size() / 2; ++ i) {
            ans += *(v.begin() + i);
        }
        cout << ans << "\n";
        v.clear();
    }
    return 0;
}
