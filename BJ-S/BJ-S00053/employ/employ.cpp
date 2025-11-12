#include <bits/stdc++.h>
using namespace std;

int n, m, d, sum = 0;
unsigned int b[507], c[507];
string s;


int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        b[i] = i;
    }

    while (true) {
        d = 0;
        for(int i = 1; i <= n; i++) {
            if (s[i-1] == '0' || c[b[i]] <= d) {
                d++;
            }
        }
        if (n-d >= m) {
            sum++;
        }
        if (!next_permutation(b+1, b+n+1)) break;
    }

    cout << sum % 998244353 << endl;



    fclose(stdin);
    fclose(stdout);
    return 0;
}
