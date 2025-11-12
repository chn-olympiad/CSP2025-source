# include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
string x, y;
struct node{
    string s1, s2;
    int a1, a2;
}a[N];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].s1 >> a[i].s2;
        for (int j = 0; j < a[i].s1.size(); j ++) if (a[i].s1[j] == 'b') a[i].a1 = j;
        for (int j = 0; j < a[i].s2.size(); j ++) if (a[i].s2[j] == 'b') a[i].a2 = j;

    }
    //for (int i = 1; i <= n; i ++) cout << a[i].a1 << " " << a[i].a2 << endl;
    for (int i = 1; i <= q; i ++){
        cin >> x >> y;
        int xx, yy, ans = 0;
        for (int j = 0; j < x.size(); j ++) if (x[j] == 'b') xx = j;
        for (int j = 0; j < y.size(); j ++) if (y[j] == 'b') yy = j;
        for (int j = 1; j <= n; j ++) if (a[j].a1 - a[j].a2 == xx - yy && min(a[j].a1, a[j].a2) <= min(xx, yy) && (a[j].s1.size() - max(a[j].a1, a[j].a2)) <= (x.size() - max(xx, yy))) ans ++;
        cout << ans << endl;
    }
    return 0;
}
