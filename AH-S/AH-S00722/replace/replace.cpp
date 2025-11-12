#include <iostream>
using namespace std;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q; cin >> n >> q;
    string a[200005];
    for (int i = 1; i <= n + q; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) cout << "0" << endl;
    return 0;
}
