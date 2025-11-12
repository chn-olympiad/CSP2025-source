#include <iostream>
using namespace std;
using ll = long long;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ll n, m, a, g, p = 1;
    // n:lie  m:hang  a:xiao ming chen ji
    // g:shu ru de chen ji  p:xiao ming de pai min
    cin >> n >> m;
    n *= m;
    cin >> a;
    for (int i = 1; i < n; ++i) {
        cin >> g;
        if (g > a) ++p;
    }
    n /= m;
    ll hang, lie;
    if (p % n == 0) {
        lie = p / n;
        hang = (lie % 2) ? n : 1;
    }
    else {
        hang = p % n;
        if (p / n % 2) hang = n - hang + 1;
        lie = p / n + 1;
    }
    printf("%d %d", lie, hang);
    return 0;
}
