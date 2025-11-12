#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int n,ans;
int a[5010];
void dfs(int i,int all,int MAX,int many){
    if(i > n){
        if(all > MAX * 2 && many >= 3){
            ans++;
            ans %= MOD;
        }
        return;
    }
    dfs(i + 1,all + a[i],max(a[i],MAX),many + 1);
    dfs(i + 1,all,MAX,many + 1);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1,0,0,0);
    cout << ans % MOD;

    return 0;
}
