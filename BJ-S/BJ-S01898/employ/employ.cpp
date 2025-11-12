

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = s; i <= t; i++)
#define per(i, s, t) for(int i = t; i >= s; i--)

int n, m;
bool s[509];
int c[509];
int p[509];

bool Check (int a[]) {

    int cur = 0;
    int cnt = 0;

    rep (i, 1, n) {
        if (cur < c[a[i]] && s[i]) {
            cnt++;
        }

        else {
            cur++;
        }
    }

    return cnt >= m;

}

int res = 0;

int Find1 (int num) {

    int res = 0;

    while (num) {
        res += (num & 1);
        num >>= 1;    
    }

    return res;

}

ll fac = 1;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;

    rep (i, 1, n) {
        char ch;
        
        cin >> ch;

        s[i] = ch - '0';
    }

    rep (i, 1, n) {
        cin >> c[i];

        p[i] = i;
        fac *= i;
    }

    res += Check(p);

    int cur = 1;

    while (cur < fac) {
        next_permutation(p + 1, p + n + 1);
        res += Check(p);
        cur++;
    }

    cout << res << '\n';

    return 0;

}