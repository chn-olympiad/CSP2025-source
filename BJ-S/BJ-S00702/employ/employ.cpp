/*
META:
Status=Give up,Locked
Guess Score=4
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const long long P = 998244353;

long long n, m;
long long trash[500];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> trash[i];
    for (int i = 1; i <= n; i++) cin >> trash[i];
    long long mul = 1;
    for (; m; m--, n--) {
        mul = (mul * n) % P;
    }
    cout << mul << endl;
    return 0;
}
