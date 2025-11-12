#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> vc;
    vector<int> maxs;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }
    int cnt = 0;
    int a, b, tmp;
    bool io = false;
    for (int i = 0; i < n; i++) {
        b = vc[i] ^ vc[i + 1];
        if (b == k) {
            maxs.push_back(1);
            continue;
        }
        cnt = 1;
        for (int j = 2; j <= n - i; j++) {
            a = b ^ vc[i + j];
            b = a;
            if (b == k) {
                cnt++;
                io = true;
                break;
            }
            cnt++;
            io = false;
        }
        if (!io) {
            maxs.push_back(0);
        }
        else {
            maxs.push_back(cnt);
        }
        cnt = 0;
    }
    sort(maxs.begin(), maxs.end());
    reverse(maxs.begin(), maxs.end());
    cout << maxs[0];
    return 0;
}
