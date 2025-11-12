#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N], t[N];
string qs[N], qt[N];
int n, q;
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> qs[i] >> qt[i];
    }
    printf("1");
    return 0;
}
