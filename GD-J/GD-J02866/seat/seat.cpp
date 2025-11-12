#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl "\n"
using namespace std;
double n, m, rg, num = 1;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> rg;
    for (int i = 2; i <= n * m; i++) {
        int input;
        cin >> input;
        num += input > rg;
    }
    // cout << num << endl;
    int w = ceil(num / m);
    cout << w << " ";
    cout << (w % 2 == 0 ? n - (num - (w - 1) * n) + 1 : num - (w - 1) * n);
    return 0;
}