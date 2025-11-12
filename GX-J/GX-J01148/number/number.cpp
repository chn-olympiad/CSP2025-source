#include <iostream>
#include <algorithm>
using namespace std;
char s[1000010];
int ans[1000010];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int n = 0;
    for (int i = 0; i < sizeof(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans[n++] = (s[i] - '0');
        }
    }
    sort(ans, ans+n+1,cmp);
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    return 0;
}
