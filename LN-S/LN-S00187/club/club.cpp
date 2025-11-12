#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

int a[200005][3];
int aa[200005], a_top;
int bb[200005], b_top;
int cc[200005], c_top;

bool cmp1(int aaaaa, int bbbbb) {
    if ((max(a[aaaaa][1], a[aaaaa][2]) - max(a[bbbbb][1], a[bbbbb][2])) < (a[aaaaa][0] - a[bbbbb][0])) return 0;
    return 1;
}
bool cmp2(int aaaaa, int bbbbb) {
    if ((max(a[aaaaa][0], a[aaaaa][2]) - max(a[bbbbb][0], a[bbbbb][2])) < (a[aaaaa][1] - a[bbbbb][1])) return 0;
    return 1;
}
bool cmp3(int aaaaa, int bbbbb) {
    if ((max(a[aaaaa][1], a[aaaaa][0]) - max(a[bbbbb][1], a[bbbbb][0])) < (a[aaaaa][2] - a[bbbbb][2])) return 0;
    return 1;
}
/*
bool cmp2(int aaaaa, int bbbbb) {
    if (a[aaaaa][1] < a[bbbbb][1]) return 1;
    if (a[aaaaa][1] == a[bbbbb][1]) {
        if (max(a[aaaaa][0], a[aaaaa][2]) > max(a[bbbbb][0], a[bbbbb][2])) return 1;
    }
    return 0;
}
bool cmp3(int aaaaa, int bbbbb) {
    if (a[aaaaa][2] < a[bbbbb][2]) return 1;
    if (a[aaaaa][2] == a[bbbbb][2]) {
        if (max(a[aaaaa][1], a[aaaaa][0]) > max(a[bbbbb][1], a[bbbbb][0])) return 1;
    }
    return 0;
}*/

void out1() {
    for (int i = 0; i < a_top; i++) cout << aa[i] << ' '; cout << endl;
    for (int i = 0; i < b_top; i++) cout << bb[i] << ' '; cout << endl;
    for (int i = 0; i < c_top; i++) cout << cc[i] << ' '; cout << endl;
}

void solve() {
    a_top = 0, b_top = 0, c_top = 0;
    memset(aa, 0, sizeof(aa));memset(bb, 0, sizeof(bb));memset(cc, 0, sizeof(cc));
    memset(a, 0, sizeof(a));

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
        if ((a[i][0] > a[i][1]) && (a[i][0] > a[i][2])) {
            aa[a_top++] = i;
        }
        else if ((a[i][1] >= a[i][0]) && (a[i][1] > a[i][2])) {
            bb[b_top++] = i;
        }
        else if ((a[i][2] >= a[i][1]) && (a[i][2] >= a[i][0])) {
            cc[c_top++] = i;
        }
        else {
            cc[c_top++] = i;
        }
    }

    //out1();


    ll ans = 0;
    if (a_top > (n / 2)) {
        sort(aa, aa + a_top, cmp1);
        for (int i = 0; (i + (n / 2)) < a_top; i++) {
            if (a[aa[i]][1] > a[aa[i]][2]) bb[b_top++] = aa[i];
            else cc[c_top++] = aa[i];
        }
        for (int i = a_top - (n / 2); i < a_top; i++) {
            ans += a[aa[i]][0];
        }
    } else if (b_top > (n / 2)) {
        sort(bb, bb + b_top, cmp2);
        for (int i = 0; (i + (n / 2)) < b_top; i++) {
            if (a[bb[i]][2] > a[bb[i]][0]) cc[c_top++] = bb[i];
            else aa[a_top++] = bb[i];
        }
        for (int i = b_top - (n / 2); i < b_top; i++) {
            ans += a[bb[i]][1];
        }
    } else if (c_top > (n / 2)) {
        sort(cc, cc + c_top, cmp3);
        for (int i = 0; (i + (n / 2)) < c_top; i++) {
            if (a[cc[i]][1] > a[cc[i]][0]) bb[b_top++] = cc[i];
            else aa[a_top++] = cc[i];
        }
        for (int i = c_top - (n / 2); i < c_top; i++) {
            ans += a[cc[i]][2];
        }
    }

    //out1();

    if (a_top <= (n / 2)) {
        for (int i = 0; i < a_top; i++) ans += a[aa[i]][0];
    }
    if (b_top <= (n / 2)) {
        for (int i = 0; i < b_top; i++) ans += a[bb[i]][1];
    }
    if (c_top <= (n / 2)) {
        for (int i = 0; i < c_top; i++) ans += a[cc[i]][2];
    }
    cout << ans << endl;
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
