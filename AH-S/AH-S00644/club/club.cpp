#include <bits/stdc++.h>
using namespace std;

#define filename "club"
#define multicases

#define inf 0x3f3f3f3f
#define Linf 0x3f3f3f3f3f3f3f3f
#define upw(i, a, b) for(int i = (a); i <= (b); ++i)
#define dnw(i, a, b) for(int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

template<class T> bool vmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool vmax(T &a, T b) { return b > a ? a = b, 1 : 0; }
template<class T> void clear(T &a) { a.swap(T()); }

const int N = 1e5+5;

#define int long long

int n, a[N][4];

int b[N], c[4];

void WaterM() {
    cin >> n;
    upw(i, 1, n) upw(j, 1, 3) scanf("%lld", &a[i][j]);

    int mxc = 0, ans = 0;
    upw(i, 1, n) {
        int mx = -inf;
        upw(j, 1, 3) if(vmax(mx, a[i][j])) b[i] = j;
        ++c[b[i]];
        ans += mx;
    }
    upw(i, 1, 3) vmax(mxc, c[i]);
    if(mxc > n/2) {
        priority_queue<pii, vector<pii>, greater<pii> > H;
        upw(i, 1, n) if(c[b[i]] == mxc) {
            upw(j, 1, 3) if(j != b[i]) {
                H.emplace(a[i][b[i]] - a[i][j], i);
            }
        }

        vector<int> used(n+1);
        int round = 0;
        while(round < (mxc - n/2)) {
            pii top = H.top(); H.pop();
            int val = top.first, i = top.second;
            if(used[i]) continue;
            used[i] = 1;
            ans -= val;
            ++round;
        }
        //cerr << mxc << '\n';
        //cerr << "abc\n";
    }
    cout << ans << '\n';

    upw(i, 1, 3) c[i] = 0;
}

signed main() {
#ifdef filename
    freopen(filename".in", "r", stdin);
    freopen(filename".out", "w", stdout);
#endif // filename

    signed _ = 1;
#ifdef multicases
    scanf("%d", &_);
#endif // multicases

    while(_--) WaterM();
}
