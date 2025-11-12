#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 200;


int a[N][4];
int vis[N][4];

int n;
int ans = 0;

void dfs(int now) {
    if (now == n + 1) {
        int res = 0;
        int a1 = 0, a2 = 0, a3 = 0, t2 = 0;
        for (int i = 1; i <= n; i ++) {
            t2 = 0;

            for (int j = 1; j <= 3; j ++) {
                if (vis[i][j]) t2 ++;
                if (vis[i][j] && j == 1) a1 ++;
                if (vis[i][j] && j == 2) a2 ++;
                if (vis[i][j] && j == 3) a3 ++;
//                cout << vis[i][j];
            }
//            if (t2 != 1) return ;
//            cout << endl;
        }
//        cout << endl;
        if (a1 > n/2 || a2 > n / 2 || a3 > n / 2) return ;

        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) {
                if (vis[i][j] == 1) res += a[i][j];
            }
        }

//        cout << res <<endl;

        ans = max(ans, res);

        return ;
    }


    for (int j = 1; j <= 3; j ++) {
        vis[now][j] = 1;
        dfs(now + 1);
        vis[now][j] = 0;
    }



}

void work() {

    ans = 0;

    cin >> n;

    int tmp1 = 0, tmp2 = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        tmp1 += a[i][2];
        tmp2 += a[i][3];
    }

    if (tmp1 == tmp2 && tmp1 == 0) {
        vector<int> b;

        for (int i = 1; i <= n; i ++) {
            b.push_back(a[i][1]);
        }

        sort(b.begin(), b.end());

        for (int i = b.size() - 1; i >= n / 2; i --) {
            ans += b[i];
        }
        cout << ans <<endl;

        return ;
    }

    dfs(1);

    cout << ans <<endl;




}

signed main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;

    while (t --) {
        work ();
    }


    return 0;
}
