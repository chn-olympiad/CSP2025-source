// club.cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct dat{
    int x, y, z, a;
    int operator[](int i) {
        if (i == 1) return x;
        if (i == 2) return y;
        return z;
    }
} x[N];

dat f[N][5];
const int D[5][5] = {{},{1,0,0},{0,1,0},{0,0,1}};

//void solve() {
//    int n;
//    cin >> n;
//    bool A = true;
//    bool B = true;
//
//    for (int i = 1; i <= n; i++) {
//            cin >> x[i].a >> x[i].b >> x[i].c;
//            A &= (x[i].b == 0 && x[i].c == 0);
//            B &= (x[i].c == 0);
//    }
//    if (A) {
//        sort(x+1,x+n+1, [](d a, d b) {
//             return a.a > b.a;
//        });
//
//        long sum = 0;
//        for (int i = 1; i <= n / 2; i++)
//            sum += x[i].a;
//        cout << sum << endl;
//    }
//    else {
//        throw bad_alloc();
//    }
//}

void solve() {
    int n;
    cin >> n;
    bool A = true;
    bool B = true;
    for (int i = 1; i <= n; i++) {
            cin >> x[i].x >> x[i].y >> x[i].z;
            A &= (x[i].y == 0 && x[i].z == 0);
            B &= (x[i].z == 0);
    }

    //f[0][1] = f[0][2] = f[0][3] = {0, 0, 0, 0};
    memset(f, 0, sizeof f);
    if (A) {
        sort(x+1, x+n+1, [](dat a, dat b) {
             return a.x > b.x;
        });

        long sum = 0;
        for (int i = 1; i <= n / 2; i++)
            sum += x[i].a;
        cout << sum << endl;
    }
    else {
        sort(x+1,x+n+1, [](dat x, dat y) {
            return x.y > y.y;
        });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            int mxa = -1e9;
            for (int k = 1; k <= 3; k++) {
                if (j == 1 && f[i-1][k].x == n / 2) continue;
                if (j == 2 && f[i-1][k].y == n / 2) continue;
                if (j == 3 && f[i-1][k].z == n / 2) continue;
                mxa = max(mxa, f[i-1][k].a+x[i][j]);
            }
            if (mxa == -1e9) continue;

            if (mxa == f[i-1][1].a+x[i][j]) f[i][j] = {f[i-1][1].x + D[j][0], f[i-1][1].y + D[j][1], f[i-1][1].z + D[j][2], mxa};
            else if (mxa == f[i-1][2].a+x[i][j]) f[i][j] = {f[i-1][2].x + D[j][0], f[i-1][2].y + D[j][1], f[i-1][2].z + D[j][2], mxa};
            else f[i][j] = {f[i-1][3].x + D[j][0], f[i-1][3].y + D[j][1], f[i-1][3].z + D[j][2], mxa};

        }
    }
    cout << max({f[n][1].a,f[n][2].a,f[n][3].a}) << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    int t;

    cin >> t;
    while (t--) solve();
}
