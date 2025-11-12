#include <bits/stdc++.h>
using namespace std;
int t;
int n,club1[50005],club2[50005],club3[50005],tot1,tot2,tot3;
struct str{
    int py1,py2,py3,zf;
    int x,y,z;
}a[100005];
bool cmp1(str p,str q) {
    return p.x > q.x;
}
bool cmp2(str p,str q) {
    return p.y > q.y;
}
bool cmp3(str p,str q) {
    return p.z > q.z;
}
bool cmp4(str p,str q) {
    return p.zf > q.zf;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        tot1 = 0,tot2 = 0,tot3 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            a[i].zf = a[i].x + a[i].y + a[i].z;
        }
        sort(a + 1,a + n + 1,cmp1);
        for (int i = 1; i <= n; i++) {
            a[i].py1 = i;
        }
        sort(a + 1,a + n + 1,cmp2);
        for (int i = 1; i <= n; i++) {
            a[i].py2 = i;
        }
        sort(a + 1,a + n + 1,cmp3);
        for (int i = 1; i <= n; i++) {
            a[i].py3 = i;
        }
        sort(a + 1,a + n + 1,cmp4);
        for (int i = n; i >= 1; i--){
            if (a[i].py1 <= a[i].py2 && a[i].py1 <= a[i].py3 && tot1 < (n / 2)) {
                club1[++tot1] = i;
            }
            else if (a[i].py2 <= a[i].py1 && a[i].py2 <= a[i].py3 && tot2 < (n / 2)) {
                club2[++tot2] = i;
            }
            else if (a[i].py3 <= a[i].py1 && a[i].py3 <= a[i].py2 && tot3 < (n / 2)) {
                club3[++tot3] = i;
            }
        }
        int ans = 0;
        for (int i = 1; i <= tot1; i++) {
            ans += a[club1[i]].x;
        }
        for (int i = 1; i <= tot2; i++) {
            ans += a[club2[i]].y;
        }
        for (int i = 1; i <= tot3; i++) {
            ans += a[club3[i]].z;
        }
        cout << ans << endl;
    }
    return 0;
}
