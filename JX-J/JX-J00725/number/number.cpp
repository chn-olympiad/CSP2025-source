#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int cnt;
int main () {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int cnt = 1, n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[cnt] = s[i] - '0';
            cnt++;
        }
    }
    for (int i = 1; i < cnt; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 1; i < cnt; i++) {
        cout << a[i];
    }
    return 0;
}
//hao wu liao, guo ran, xiang wo zhe zhong jv ruo, csp jiu shi lai chi dong xi jia lv you de
//ting shuo dong tian jie jie hao xiang yao tui yi le
//wo de dong tian jie jie  aaaaaaaa QWQ
//xi wang yi hou hai ke yi he dong tian jie jie zai jian ba
//zhi neng zhu ta csp he whk rp dou += inf le
//zai ci ye zhu suo you ren csp rp++!
