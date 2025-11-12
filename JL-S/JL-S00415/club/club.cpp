#include <bits/stdc++.h>
using namespace std;
int n;
int am[100010],bm[100010],cm[100010];
int ap,bp,cp;
int ans;
void dfs(int man,int x){
    if (ap > n / 2 || bp > n / 2 || cp > n / 2){
        return;
    }
    if (x == n + 1){
        ans = max(ans,man);
        return;
    }
    ap++;
    dfs(am[x] + man,x + 1);
    ap--;
    bp++;
    dfs(bm[x] + man,x + 1);
    bp--;
    cp++;
    dfs(cm[x] + man,x + 1);
    cp--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for (int q = 1;q <= t;q++){
        ap = 0;
        bp = 0;
        cp = 0;
        cin >> n;
        for (int i = 1;i <= n;i++){
            cin >> am[i] >> bm[i] >> cm[i];
        }
        dfs(0,1);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
