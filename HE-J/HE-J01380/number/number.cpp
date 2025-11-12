#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int ans, p = 1;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            a[p++] = (int)(s[i] - '0');
    p--;
    sort(a + 1, a + p + 1);
    while (p >= 1)
        ans = ans * 10 + a[p--];
    cout << ans;
    return 0;
}
