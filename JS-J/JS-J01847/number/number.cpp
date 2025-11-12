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

long long cnt[10];

int main() {

    finout("number");
    use_iostream();

    // input
    string s;
    cin >> s;
    
    // program [O(s.size())]
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            ++cnt[s[i] ^ 48];
        }
    }

    // output
    for (long long i = 9; i > -1; --i) {
        while (cnt[i]--) {
            cout << i;
        }
    }

    cout << endl;
    return 0;
}