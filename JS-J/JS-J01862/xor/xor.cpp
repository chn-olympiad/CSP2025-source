#include<iostream>
using namespace std;
const int N = 2e5 + 5;
int n, k, one, a[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] == 1) one ++;
    }
    if(k == 0) {
        if(one % 2 == 0) cout << 2;
        else cout << 1;
    }
    else cout << one;
    return 0;
}
