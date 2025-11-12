#include <bits/stdc++.h>

using std::cin;
using std::cout;

int n, m;
struct person{
    int c;
    bool is_out;
}p[1000];
std::string s;

long long f(int cnt, int day, int lose) {
    if (day >= n && cnt >= m) {
        return 1;
    }

    long long sum = 0;
    std::vector<int> out;
    for (int i = 0; i < n; ++i) {
        if (lose >= p[i].c && !p[i].is_out) {
            p[i].is_out = true;
            out.push_back(i);
            ++lose;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i].is_out) continue;
        p[i].is_out = true;
        int add = 0;
        if (s[day]=='0') {
            ++lose;
            out.push_back(i);
        } else {
            ++add;
        }
        sum += f(cnt + add, day + 1, lose);
        p[i].is_out = false;
    }
    int len = out.size();
    for (int i = 0; i < len; ++i) {
        p[out[i]].is_out = false;
    }
    return sum%998244353;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].c;
        p[i].is_out = false;
    }
    cout << f(0, 0, 0);
    return 0;
}
