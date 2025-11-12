#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    vector<int> lg;
    vector<int> as;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        lg.push_back(tmp);
    }
    int ans = 0;
    for (int i = 1; i <= n; iz++) {
        for (int j = 1; j <= n; j++) {
            ans += lg[j];
        }
        as.push_back(ans);
        ans = 0;
    }
    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());
    cout << as[0];


    return 0;
}
