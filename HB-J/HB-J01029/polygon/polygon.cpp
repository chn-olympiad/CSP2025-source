#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int n;
int a[5005];
int ans;
void dfs(int now,int sum,int maxx){
    if(sum > maxx*2) ans++;
    ans%= MOD;
    for(int i = now+1; i <= n; i++){
        dfs(i,sum+a[i],max(maxx,a[i]));
    }
}
bool c = true;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1) c = false;
    }
    if(c){
        for(int i = 1; i <= n; i++){
            int now = 1;
            for(int j = 1; j <= i; j++) now *= (n-j+1);
            for(int j = 1; j <= i; j++) now /= j;
            now %= MOD;
            ans += now;
            ans %= MOD;
        }
        cout << ans;
        return 0;
    }
    dfs(0,0,0);
    cout << ans;
    return 0;
}
//QWQ  64pts / 40pts
