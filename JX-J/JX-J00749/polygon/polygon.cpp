#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n,res = 0;
int a[5005];
int C[5005][5005];
void dfs(int step,int sum,int maxx,int he){
    if(step == n + 1){
        if(sum >= 3){
            if(he > maxx * 2){
                res ++;
            }
        }
        return ;
    }
    dfs(step + 1,sum + 1,max(maxx,a[step]),he + a[step]);
    dfs(step + 1,sum,maxx,he);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == j) C[i][j] = 1;
                else C[i][j] = (C[i - 1][j] + C[i][j - 1]) % Mod;
            }
        }
    if(n >= 500){
        long long ans = 0;
        for(int i = 3; i <= n; i ++){
            ans += C[n][i];
            ans %= Mod;
        }
        cout << ans << endl;
    }else{
        dfs(1,0,-1,0);
        cout << res << endl;
    }

    return 0;
}
