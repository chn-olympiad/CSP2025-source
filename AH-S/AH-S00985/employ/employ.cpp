#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r",stdin);
	freopen("employ.out", "w", stdout);
    srand(time(0));
    int x = rand();
    int ans = 0;
    for (int i = 1 ; i <= x%10000; ++i) ans = (ans + rand()) % 998244353;
    cout << ans <<"\n";

    return 0;
}
