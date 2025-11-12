#include<bits/stdc++.h>
#define MAXN 210
using namespace std;
namespace SHuxinn{
    int n;
    int a[MAXN][4];
    int ans;
    int cnta[4] = {0};
    void dfs(int stp , int cnt) {
        if(stp == n) {
            ans = max(ans , cnt);
            return;
        }
        for (int i = 1 ; i <= 3; i ++) {
            if(cnta[i] >= n / 2) continue;
            cnta[i] ++;
            dfs(stp + 1 , cnt + a[stp + 1][i]);
            cnta[i] --;
        }

    }
    void Sx5(){
        ans = -1e9;
        cin >> n;
        for (int i = 1 ; i <= n ; i ++)
            for (int j = 1 ; j <= 3 ; j ++)
                cin >> a[i][j];
        dfs(0 , 0);
        cout << ans << endl;
        return;
    }
}
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    SHuxinn::Sx5();
    return 0;
}
