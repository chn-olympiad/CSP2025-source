#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;
    string ans[1000000];
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] < 58) {
            ans[cnt] = s[i];
            cnt++;
        }
    }

    sort(ans, ans + cnt - 1);

    for (int i = cnt; i > 0; i--) {
        cout << ans[i];
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
