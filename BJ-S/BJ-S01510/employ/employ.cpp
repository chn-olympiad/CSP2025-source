#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
const int M = 998244353;

int n, m;
string s;
int c[N];
long long sum = 0, cnt = 0;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '1') {
            cout << "0" << "\n";
            return 0;
        }
    }
    for (int k = m; k <= n; k++) {
        sum = n;
        for (int i = 1; i < k; i++) {
            //cout << n - i << " ";
            sum *= (n - i) % M;
        }
        //cout << "\n";
        cnt += sum;
    }
    cout << cnt % M <<endl;
    return 0;
}
