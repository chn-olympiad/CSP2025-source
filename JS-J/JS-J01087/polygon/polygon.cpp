#include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 998244353;
int n, a[N], tsum; bool tttt = true;
void findn(vector <int> v, int sum, int mt, int f) { //and find some other one
    //   [mt * 2 - (tx + ty)]  <  x  <  mt
    int xmi = lower_bound(a + 1, a + n + 1, mt * 2 - sum + 1) - a;
    int xma = lower_bound(a + 1, a + n + 1, mt) - a - 1;
    //and don't have a_x , a_y
    int re = 0;
    for (int i = 0; i < v.size(); i++) {
        if (mt * 2 - (sum) + 1 <= v[i] && v[i] < mt) {
            re++;
            //cout << mt * 2 - sum + 1 << " " << v[i] << " " << mt << "\n";
        }
    }
    //cout << "re:" << re << "\n";
    if (xma - xmi - re + 1 > 0 && v.size() >= 3) {
        tsum += (xma - xmi - re + 1);
        tsum %= M;
    }
    //cout << "xma:" << xma << " xmi:" << xmi << "\n";
    for (int i = f + 1; i <= n; i++) {
        vector <int> vv; vv = v;
        vv.push_back(a[i]);
        findn(vv, sum + a[i], max(mt, a[i]), i);

    }

    //for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    //cout << "\n";
}
signed main() {
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) tttt = false;
    }
    if  (tttt == true) {
        tsum = 1;
        for (int i = 4; i <= n; i++) {
            tsum *= i;
            tsum %= M;
        }
        cout << tsum;
        return 0;
    }
    sort(a + 1, a + n + 1);
    // find two number;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            findn( { a[i] , a[j] } , a[i] + a[j], max(a[i], a[j]), j);
        }
    }
    //cout << "\n";
    cout << tsum / 2;
    return 0;
}
