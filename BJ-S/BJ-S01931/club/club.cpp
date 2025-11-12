#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define pii pair < int , int >
#define mp(i, j) make_pair(i, j)

const int N = 1e5 + 5;
int t, n;
struct node {
    int mx, se;
} a[N];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t --) {
        vector < int > v[3];
        scanf("%d", &n);
        int ans = 0;
        int k = n / 2;
        for(int i = 1; i <= n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            vector < int > vec;
            vec.push_back(x), vec.push_back(y), vec.push_back(z);
            sort(vec.begin(), vec.end());
            a[i].mx = vec[2], a[i].se = vec[1];
            if(a[i].mx == x) v[0].push_back(i);
            else if(a[i].mx == y) v[1].push_back(i);
            else v[2].push_back(i);
            ans += a[i].mx;
        }
        int p = -1;
        for(int i = 0; i < 3; i++) if(v[i].size() > k) p = i;
        if(p == -1) {
            printf("%d\n", ans);
            continue;
        }
        int siz = v[p].size();
        vector < int > vec;
        for(int i : v[p]) vec.push_back(a[i].mx - a[i].se);
        sort(vec.begin(), vec.end());
        for(int i = 0; i < siz - k; i++) ans -= vec[i];
        printf("%d\n", ans);
    }
    return 0;
}
