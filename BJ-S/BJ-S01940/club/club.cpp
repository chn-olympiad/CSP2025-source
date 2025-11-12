#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int T,n,a[4][M],f[M];
long long mx,ans,ret;
void dfs(int x){
    if(x > n){
        ret = max(ans,ret);
        return;
    }
    for(int i = 1; i <= 3; i ++){
        if(f[i] < mx){
            f[i]++;
            ans+=a[i][x];
            dfs(x+1);
            ans -= a[i][x];
            f[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>T;
    while(T--){
        ans=0,ret=0;
        cin >> n;
        mx = n/2;
        for(int i = 1; i <= n; i++){
            cin >> a[1][i] >> a[2][i] >> a[3][i];
        }
        dfs(1);
        cout <<ret <<endl;
    }
    return 0;

}
