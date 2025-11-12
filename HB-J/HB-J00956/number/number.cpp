#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;

string s;
int cnt, a[N];
bool cmp(int a, int b) {return a > b;}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
        if (s[i] >= '0' && s[i] <= '9') 
            a[++cnt] = int(s[i] - '0');
    sort(a + 1, a + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++) cout << a[i];
    return 0;
}
