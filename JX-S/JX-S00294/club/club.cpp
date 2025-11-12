#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;
using LL = long long;
const int N = 1e5 + 5;
int n;
PII a[N][3];
void solve(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ){
        for (int j = 0; j < 3; j ++ )
            scanf("%d", &a[i][j].x), a[i][j].y = j;
        sort(a[i], a[i] + 3, greater<PII>());
    }
    int cnt[3] = {0, 0, 0};
    LL res = 0;
    priority_queue<int, vector<int>, greater<int>> q[3];
    for (int i = 1; i <= n; i ++ ){
        cnt[a[i][0].y] ++ ;
        res += a[i][0].x;
        q[a[i][0].y].push(a[i][0].x - a[i][1].x);
    }
    if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
        printf("%lld\n", res);
    else {
        int t = 0, base = 0;
        for (int i = 0; i < 3; i ++ )
            if (cnt[i] > n / 2){
                t = cnt[i] - n / 2;
                base = i;
                break;
            }
        for (int i = 1; i <= t; i ++ )
            res -= q[base].top(), q[base].pop();
        printf("%lld\n", res);
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T -- ) solve();
    return 0;
}

