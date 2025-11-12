#include<bits/stdc++.h>
using namespace std;

struct people {
    int num;
    int a;
    int b;
    int c;
    int wh;
    int away;
};

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int ans = 0;
        people p[n];
        int ah[n];
        int ahead = 0;
        int bh[n];
        int bhead = 0;
        int ch[n];
        int chead = 0;
        for(int j = 0; j < n; ++j) {
            p[j].num = j;
            cin >> p[j].a >> p[j].b >> p[j].c;
            if(p[j].a >= p[j].b && p[j].a >= p[j].c) {
                ans = ans + p[j].a;
                ah[ahead] = j;
                ++ahead;
            } else if(p[j].b >= p[j].a && p[j].b >= p[j].c) {
                ans = ans + p[j].b;
                bh[bhead] = j;
                ++bhead;
            } else {
                ans = ans + p[j].c;
                ch[chead] = j;
                ++chead;
            }
        }
        if(ahead > n / 2) {
            int aw[n];
            for(int j = 0; j < ahead; ++j) {
                p[ah[j]].away = p[ah[j]].a - max(p[ah[j]].b, p[ah[j]].c);
                aw[j] = p[ah[j]].away;
            }
            sort(aw, aw + ahead);
            int x = ahead - n / 2;
            for(int j = 0; j < x; ++j) {
                ans = ans - aw[j];
            }
        }

        if(bhead > n / 2) {
            int bw[n];
            for(int j = 0; j < bhead; ++j) {
                p[bh[j]].away = p[bh[j]].b - max(p[bh[j]].a, p[bh[j]].c);
                bw[j] = p[bh[j]].away;
            }
            sort(bw, bw + bhead);
            int x = bhead - n / 2;
            for(int j = 0; j < x; ++j) {
                ans = ans - bw[j];
            }
        }

        if(chead > n / 2) {
            int cw[n];
            for(int j = 0; j < chead; ++j) {
                p[ch[j]].away = p[ch[j]].c - max(p[ch[j]].a, p[ch[j]].b);
                cw[j] = p[ch[j]].away;
            }
            sort(cw, cw + chead);
            int x = chead - n / 2;
            for(int j = 0; j < x; ++j) {
                ans = ans - cw[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}