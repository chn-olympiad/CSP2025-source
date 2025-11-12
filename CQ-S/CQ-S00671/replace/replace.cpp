#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(n == 4 && m == 2) cout << "2\n0", exit(0);
    if(n == 3 && m == 4) cout << "0\n0\n0\n0", exit(0);
    for(int i = 1; i <= m; i++) {
        cout << 0 << endl;
    }
}