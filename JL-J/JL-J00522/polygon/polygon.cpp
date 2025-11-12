#include <bits/stdc++.h>
using namespace std;
int sticks[10000];
long long ans,n;
int chosen[10000];
void dfs(int took,int x,int he,int most){
    if (x == n + 1){
        if (took < 3){
            return;
        }else {
            if (he > 2 * most){
                ans++;
                ans %= 998244353;
                return;
            }else {
                return;
            }
        }

    }
    if (x == n && took < 2) return;
    if (x == n - 1 && took < 1) return;
    chosen[took+1] = sticks[x];
    dfs(took+1,x+1,he + sticks[x],max(most,sticks[x]));
    chosen[took+1] = 0;
    dfs(took,x+1,he,most);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> sticks[i];
    }
    dfs(0,1,0,0);
    cout << ans;
    return 0;
}
