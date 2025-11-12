#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int dp[MAXN][MAXN][MAXN];
int n;
int a[MAXN], b[MAXN], c[MAXN];
struct Node{
    int w;
    int cw;//xuan ze qi ta de
    friend bool operator <(Node x, Node y) {
        return x.cw > y.cw;
    }
}a1[MAXN], b1[MAXN], c1[MAXN];
int cnta, cntb, cntc;
void slove() {

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    cnta = cntb = cntc = 0;
    int result = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > b[i] and a[i] > c[i]) {
            a1[cnta++] = {a[i], max(b[i], c[i]) - a[i]};
            result += a[i];
        }
        else if(b[i] > a[i] and b[i] > c[i]) {
            b1[cntb++] = {b[i], max(a[i], c[i]) - b[i]};
            result += b[i];
        }
        else {
            c1[cntc++] = {c[i], max(b[i], a[i]) - c[i]};
            result += c[i];
        }

    }
    if(cnta <= n / 2 && cntb <= n / 2 && cntc <= n / 2) {
        cout << result << endl;
        return ;
    }
    //cout << cnta << ' ' << cntb << ' ' << cntc << ' ' << n << endl;
    int ccnta = cnta;
    int ccntb = cntb;
    int ccntc = cntc;
    if(cnta > n / 2) {
        //cout << 1 << endl;
        sort(a1, a1 + cnta - 1);
        for(int i = 0; i < ccnta; i++) {
            //c//out << i << ' ' << a1[i].cw << ' ' << cnta << endl;
            if(cnta <= n / 2) {
                //cout << "ok" << endl;
                cout << result << endl;
                return ;
            }
            result += a1[i].cw;
            cnta--;
        }
    }
    if(cntb > n / 2) {
        sort(b1, b1 + cntb - 1);
        for(int i = 0; i < ccntb; i++) {
            if(cntb <= n / 2) {
                cout << result << endl;
                return ;
            }
            result += b1[i].cw;
            cntb--;
        }
    }
    if(cntc > n / 2) {
        sort(c1, c1 + cntc - 1);
        for(int i = 0; i < ccntc; i++) {
            if(cntc <= n / 2) {
                cout << result << endl;
                return ;
            }
            result += c1[i].cw;
            cntc--;
        }
    }
    //cout << result << endl;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T;
    while(T--) {
        slove();
    }
    return 0;
}
