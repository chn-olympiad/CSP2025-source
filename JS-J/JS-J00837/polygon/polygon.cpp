#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005,Mod = 998244353;
int n,a[N],ans,save[N],cnt = 1;
bool used[N];
void dfs(int k,int now,int cnt){
    if(k == 0){
        int s = 0;
        for(int k = 1;k < cnt;k++){
            s += save[k];
         //   cout << save[k] << ' ';
        }
       // cout << endl;
        if(s > 2 * save[cnt - 1]){
            ans++;
            ans %= Mod;
        }
    }
    for(int i = now;i <= n;i++){
        if(!used[i]){
            used[i] = 1;
            save[cnt] = a[i];
            dfs(k - 1,i + 1,cnt + 1);
            used[i] = 0;
        }
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int j = 3;j <= n;j++){
        dfs(j,1,1);
    }
    cout << ans << endl;
    return 0;
}
