#include <bits/stdc++.h>
using namespace std;
struct node{
    int a1,a2,a3;
    int maxa;
    int ta;
    int mina;
    bool f = 0;
};
bool cmp1(node a,node b) {
    return a.a1 > b.a1;
}
bool cmp2(node a,node b) {
    return a.a2 > b.a2;
}
bool cmp3(node a,node b) {
    return a.a3 > b.a3;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int a1 = 0,a2 = 0,a3 = 0;
        int n;
        int ans = 0;
        cin >> n;
        int sx = n / 2;
        node a[100005];
        for (int i = 0;i < n;i ++) {
            cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
            a[i].maxa = max(max(a[i].a1, a[i].a2), a[i].a3);
            a[i].mina = min(min(a[i].a1, a[i].a2), a[i].a3);
        }
        sort(a, a + n, cmp1);
        for (int i = 0;i < n;i ++) {
            if(a[i].maxa == a[i].a1 && a1 < sx && a[i].f == 0) {
                a1++;
                ans += a[i].a1;
                a[i].f = 1;
            }
        }
        sort(a, a + n, cmp2);
        for (int i = 0;i < n;i ++) {
            if(a[i].maxa == a[i].a2 && a2 < sx && a[i].f == 0) {
                a2++;
                ans += a[i].a2;
                a[i].f = 1;
            }
        }
        sort(a, a + n, cmp3);
        for (int i = 0;i < n;i ++) {
            if(a[i].maxa == a[i].a3 && a3 < sx && a[i].f == 0) {
                a3++;
                ans += a[i].a3;
                a[i].f = 1;
            }
        }
        for (int i = 0;i < n;i ++) {
            if (a[i].f == 0) {
                if( ( (a[i].a1 >= a[i].a2 && a[i].a1 <= a[i].a3) || (a[i].a1 <= a[i].a2 && a[i].a1 >= a[i].a3) ) && a1 < sx) {
                    ans += a[i].a1;
                    a1++;
                } else if( ( (a[i].a2 >= a[i].a1 && a[i].a2 <= a[i].a3) || (a[i].a2 <= a[i].a1 && a[i].a1 >= a[i].a3) ) && a2 < sx) {
                    ans += a[i].a2;
                    a2++;
                } else if( ( (a[i].a3 >= a[i].a2 && a[i].a3 < a[i].a1) || (a[i].a3 <= a[i].a2 && a[i].a3 >= a[i].a1) ) && a3 < sx) {
                    ans += a[i].a3;
                    a3++;
                }
            }
        }
        for (int i = 0;i < n;i ++) {
            if (a[i].f == 0) {
                ans += a[i].mina;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
