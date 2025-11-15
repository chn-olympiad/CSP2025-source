#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N][4], ans;
inline void compute(){
    ans = 0;
    vector<vector<int> > wl(4); //waiting list
    for (int i = 1; i <= n; i++){
        //cout << i << endl;
        int p = 0, maxi, idx, secmaxi;
        for (int j = 1; j <= 3; j++){
            if (a[i][j] > a[i][p]){
                p = j;
            }
        }
        //cout << p << endl;
        maxi = a[i][p];
        idx = p;
        a[i][p] = -1;
        p = 0;
        for (int j = 1; j <= 3; j++){
            if (a[i][j] > a[i][p]){
                p = j;
            }
        }
        secmaxi = a[i][p];
        wl[idx].push_back(maxi - secmaxi);
        ans += maxi;
    }
    /*for (int i = 1; i <= 3; i++){
        for (int j : wl[i]){
            cout << j << ' ';
        }
        cout << endl;
    }*/
    //cout << ans << '\n';
    for (int i = 1; i <= 3; i++){
        if (wl[i].size() > n / 2){
            sort(wl[i].begin(), wl[i].end());
            for (int j = 0; j < wl[i].size() - n / 2; j++){
                ans -= wl[i][j];
            }
            break;
        }
    }
    return;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            a[i][0] = -1;
            scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
        }
        compute();
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

