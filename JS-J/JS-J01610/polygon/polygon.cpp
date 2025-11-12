#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans, id[5005];
void s(int length, int sum, int maxa, set<int> st) {
    if (length == 0) {
        if (sum > 2 * maxa) {
            ans++;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {

        if (st.count(id[i]) == 0) {
            //for (auto i : st) {
                //cout << a[i] << ' ';
            //}
            //cout << endl;
            st.insert(id[i]);
            s(length - 1, a[i] + sum, max(maxa, a[i]), st);
        }
    }
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = i;
    }
    for (int i = 3; i <= n; i++) {
        set<int> st;
        s(i, 0, -1, st);
    }
    cout << ans;
    cout << '\n';
    return 0;
}
