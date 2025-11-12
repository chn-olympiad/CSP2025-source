#include <iostream>
#include <string>

using namespace std;
string s;
int cnt[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (auto c: s) {
        if (c >= '0' && c <= '9') {
            int num = c - '0';
            cnt[num] ++;
        }
    }
    for (int i = 9; i >= 0; i --) {
        for (int j = 1; j <= cnt[i]; j ++) cout << i;
    }
    cout << '\n';
    return 0;
}
