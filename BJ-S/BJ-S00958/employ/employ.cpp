#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
string s;
ll a = 0, b = 0, ans = 0;
ll mod = 998244353;
ll ar[507],ar2[507];
void dfs(int pos, int l, int r, int sum){//1 0
    if(l>0&&ar2[pos] >= 0)sum ++;
    //cout<<"Pos="<<pos<<"l="<<l<<"r="<<r<<"sum="<<sum<<endl;
    if(pos > n){
        if(sum >= m)ans = (ans + 1)%mod;
        return;
    }
    if(l > 0)dfs(pos + 1, l-1, r,sum);
    if(r > 0){
        for(int i = pos; i <= n; i ++){
            ar2[i] --;//cout <<ar2[i]<<" ";
        }
        //cout <<"r="<<r<<endl;
        dfs(pos + 1,l,r-1,sum);
        for(int i = pos; i<=n;i++){
            ar2[i] ++;
        }
    }
}
int main(){
    freopen("project.in", "r", stdin);
    freopen("project.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < n; i ++){
        if(s[i] == '0')b ++;
        else a ++;
    }
    if(a == n){
        for(int i = 1; i <= 216497919; i ++){
            ans *= i;
            ans %= mod;
        }
        cout << ans;
        return 0;
    }
    if(a < m){
            cout << 0;
            return 0;
    }
    for(int i = 1; i <= n; i ++){
        cin >> ar[i];
        ar2[i]=ar[i];
    }
    dfs(1, a, b, 0);
    cout << ans - 1;
    return 0;
}
