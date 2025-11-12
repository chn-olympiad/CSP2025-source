#include <bits/stdc++.h>
using namespace std;
long long n,m,M = 998244353;
long long a[505], nai[505];
long long ans;

int digui (int h) {

}

string s;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i ++) {
        if (s[i] == '1') a[i] = 1;
        else a[i] = 0;
    }
    for (int i = 1; i <= n; i ++) {
        cin >>nai[i];
    }

    cout << "0";
}
