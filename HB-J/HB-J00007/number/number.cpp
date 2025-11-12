#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
string s; int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int i = 0;
    for (char c : s)
        if ('0' <= c && c <= '9')
            a[++i] = c - '0';
    sort(a + 1, a + i + 1, greater<int>());
    for (int j = 1; j <= i; j++) cout << a[j];
    return 0;
}
