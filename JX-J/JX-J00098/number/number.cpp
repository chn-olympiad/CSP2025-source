#include <iostream>
using namespace std;
using ll = long long;

const ll N = 1e6 + 1;
string s;
ll len = 1;
ll ans[N] = { 0 };
ll ss[11] = { 0 }, rr[N] = { 0 };

void sort1(ll l, ll r) {
    for (ll i = l; i <= r; ++i) {
        ++ss[ans[i] + 1];
    }
    for (ll i = 1; i <= 10; ++i) {
        ss[i] += ss[i - 1];
    }
    for (int i = r; i >= l; --i) {
        rr[ss[ans[i] + 1]] = ans[i];
        --ss[ans[i] + 1];
    }
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (ll i = 0; s[i] != '\0'; ++i) {
        if(isdigit(s[i]))  {
            ans[len] = (ll)s[i] - '0';
            ++len;
        }
    }
    sort1(1, len - 1);
    for (ll i = len - 1; i >= 1; --i) cout << rr[i];
    return 0;
}
