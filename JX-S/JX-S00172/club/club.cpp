#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int T, mid, a[N], b[N], c[N];
int n, ans = 0;
int dp[N];
int dg(int i, int a1, int b1, int c1){
    int ai = 0, bi = 0, ci = 0;
    int a2 = 0, b2 = 0, c2 = 0;
    if (a1 < mid) ai = a[i];
    if (b1 < mid) bi = b[i];
    if (c1 < mid) ci = c[i];
    ans = 0;
    if (i == 1) {
        ans = max(ai,max(bi,ci));
        a2 = ai;
        b2 = bi;
        c2 = ci;
    }else{
        a2 = dg(i-1, a1 + 1, b1, c1) + ai;
        b2 = dg(i-1, a1, b1 + 1, c1) + bi;
        c2 = dg(i-1, a1, b1, c1 + 1) + ci;
        ans = max(a2, max(b2, c2));
    }

    return ans;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        mid = n/2;
        cout << dg(n, 0, 0, 0) << endl;
    }
}
