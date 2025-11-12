#include <bits/stdc++.h>
using namespace std;
string s;
long long len, i, k, l;
long long a[1000010];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    len = s.size();
    for(i = 0; i < len; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            k++;
            a[k] = s[i] - '0';
        }
    }
    sort(a + 1, a + k + 1);
    l = false;
    for(i = k; i >= 1; i--) {
        if(a[i] == 0) {
            l = false;
        } else {
            l = true;
        }
        if(l == true)
            cout << a[i];
    }
    if(l == false) {
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
