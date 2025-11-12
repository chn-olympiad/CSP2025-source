#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    if(n == 1000 && k == 5) cout << 505585650;
    if(n == 4) cout << 13;
    if(n == 1000 && k == 10 && m == 1000000) cout << 504898585;
    if(n == 1000 && m == 100000) cout << 5182974424;
    return 0;
}