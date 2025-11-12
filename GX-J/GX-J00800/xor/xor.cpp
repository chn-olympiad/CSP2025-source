#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    int n, k, ans = 0, sum = 0,aaa = false, bbb = false;
    cin >> n >> k;
    int a[n];
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (bbb == true) bbb = false;
        if (aaa == true) {
            sum = a[i];
            aaa = false;
            bbb = true;
        }
        if (a[i] == k) {
            ans++;
            aaa = true;
            continue;
        }
        if (bbb == false) {
            sum = sum ^ a[i];
            if (sum == k) {
                ans++;
                aaa = true;
            }
        }
    }
    cout << ans;
    return 0;
}
