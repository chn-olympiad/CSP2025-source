#include <bits/stdc++.h>
using namespace std;

int n, k;
string tobin(int x) {
    string num;
    int i = 0;
    while (x > 0) {
        if (x % 2 == 1) {
            num += "1";
            x = (x - (x % 2)) / 2;
        }
        else {
            num += "0";
            x /= 2;
        }
        i++;
    }
    return num;
}

int Xor(string a, string b) {
    string r;
    int minn = min(a.length(), b.length());
    int maxn = max(a.length(), b.length());
    string mx = maxn == a.length()? a: b;
    for (int i = 0; i < maxn; i++) {
        if (i < minn) {
            if (a[i] != b[i]) r += "1";
            else r += "0";
        }
        else {
            if (mx[i] == '0') r += "0";
            else r += "1";
        }
    }
    int sum = 0;
    for (int i = 0; i < r.length(); i++) {
        if (r[i] == '1') sum += pow(2, i);
    }
    return sum;
}

int sum(int l, int r, vector<int> a) {
    int s = Xor(tobin(a[l]), tobin(a[l + 1]));
    for (int i = l + 2; i <= r; i++) {
        s = Xor(tobin(s), tobin(a[i]));
    }
    return s;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    bool PPP = true;
    bool PPPP = true;
    int zero = 0;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) PPP = false;
        if (a[i] != 1 && a[i] != 0) PPP = false;
        if (a[i] == 0) zero++;
    }
    if (k == 0 && PPP) {
        cout << n;
        return 0;
    }
    else if (k == 0) {
        cout << zero;
        return 0;
    }
    else if (k == 1 && PPPP) {
        cout << n - zero;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) {
            ans++;
            continue;
        }
        for (int j = i; j <= n; j++) {
            if (sum(i, j, a) == k) {
                i = ++j;
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
