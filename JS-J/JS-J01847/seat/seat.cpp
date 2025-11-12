#include <bits/stdc++.h>
using namespace std;

#ifdef MYDBG
#define finout(filename) (void)0
#else
#define finout(filename) freopen(filename ".in", "r", stdin);    \
                         freopen(filename ".out", "w", stdout)
#endif

#define use_iostream() ios::sync_with_stdio(false);  \
                       cin.tie(nullptr);             \
                       cout.tie(nullptr)

long long n, m;
long long a[10001];

int main() {

    finout("seat");
    use_iostream();

    // input
    cin >> n >> m;
    for (long long i = 1; i <= n * m; ++i) {
        cin >> a[i];
    }

    // program [O(n * log(n))]
    long long cur = a[1];
    sort(a + 1, a + n * m + 1);
    long long pos = n * m - (lower_bound(a + 1, a + n * m + 1, cur) - a);
    long long col = pos / n + 1;
    long long row = pos % n + 1;
    if ((col & 1) == 0) {
        row = n + 1 - row;
    }

    // output
    cout << col << ' ' << row;


    cout << endl;
    return 0;
}