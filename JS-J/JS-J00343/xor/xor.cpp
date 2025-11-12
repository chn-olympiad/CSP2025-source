#include <bits/stdc++.h>
using namespace std;
int num[] = {1};
const int N = 1e3 + 10;
int n, k, a[N], dp[N];
string s[N];
string binary(int n) {
    string s = "";
    if (n == 0) return "0";
    while (n != 0) {
        int ge = n % 2;
        n /= 2;
        s = char(ge + '0') + s;
    }
    return s;
}
string xor_(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    while (b.size() != a.size()) b = '0' + b;
    string c = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        char a1 = a[i], b1 = b[i];
        if (a1 == b1) c = '0' + c;
        else c = '1' + c;
    }
    return c;
}
int main() {
    //freopen("xor.in", "r", stdin);
    //freopen("xor.out", "w", stdout);
    for (int i = 1; i <= 20; i++)
        num[i] = num[i - 1] * 2;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = binary(a[i]);
    }
    long long cnt = 0;
    string now = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) {
            dp[i] = dp[i - 1] + 1;
            now = "0";
        }
        else {
            if (now == "0") {
                now = s[i];
            } else {
                now = xor_(now, s[i]);
                long long cnt = 0;
                for (int i = 0; i <= now.size() - 1; i++) {
                    if (now[i] == '0') continue;
                    cnt = cnt + num[now.size() - i - 1];
                }
                if (cnt == k) dp[i] = dp[i - 1] + 1;
                else dp[i] = dp[i - 1];
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
