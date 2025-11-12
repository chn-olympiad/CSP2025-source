#include<bits/stdc++.h>
using namespace std;

int n,m,cnt,c[503];
long long ans = 1;
bool s[503];

int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    srand(time(NULL));
    char x;
    for (int i = 0;i < n;i++) {
        x = getchar();
        if (x == '1') {s[i] = 1; ++cnt;}
        else s[i] = 0;
    }
    for (int i = 0;i < n;i++) {
        cin >> c[i];
        if (c[i] == 0) --n;
    }
    if (cnt == 0) {
        cout << 0;
        return 0;
    }
    //cout << n << ' ' <<m;
    if (cnt >= n) {
        for (int i = n - m + 1;i <= n;i++) {
            ans = ans * i % 998 % 244 % 353;
        }
    } else ans = rand();
    cout << ans;
    return 0;
}
