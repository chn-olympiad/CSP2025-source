#include <bits/stdc++.h>
#define endl '\n'
#define N 500050
using namespace std;
typedef long long ll;
int n;
ll k;
ll a[N];
vector<string> s;
string goal;
int p[32];
int maxl;
string to_binary(ll x) {
    string res1 = "", res2 = "";
    while(x > 0) {
        res1 += (x % 2 + '0');
        x /= 2;
    }
    for(int i = res1.length() - 1; i >= 0; i--) {
        res2 += res1[i];
    }
    maxl = max((int)res2.length(), maxl);
    return res2;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            s.push_back("0");
        }
        else {
            s.push_back(to_binary(a[i]));
        }
    }
    goal = to_binary(k);
    for(int i = 0; i < (int)s.size(); i++) {
        for(int j = s[i].length() - 1; j >= 0; j--) {
            if(s[i][j] == '1') {
                p[s[i].length() - j]++;
            }
        }
    }
    cout << *max_element(p + 1, p + n + 1);
}
