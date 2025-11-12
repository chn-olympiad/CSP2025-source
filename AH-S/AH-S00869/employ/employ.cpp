#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10,mod = 998244353;

int s[N],c[N],n,m;
int vis[N],p[N];

void solve(){

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

    cin >> n >> m;//cout << n;
    string tmp;cin >> tmp;int flag = 0;
    for(int i = 1;i <= n;i ++){
        s[i] = tmp[i - 1] - '0';//cout << s[i] << ' ';
        if(s[i] == 0) flag = 1;
    }
    for(int i = 1;i <= n;i ++) cin >> c[i];

    if(!flag){
        int sum = 0;
        for(int i = 1;i <= n;i ++) sum += (c[i] > 0);
        if(sum < m) cout << 0 << '\n';
        else{
            int ans = 1;
            for(int i = 1;i <= n;i ++){
                ans = ans * i % mod;
            }
            cout << ans << '\n';
        }
    }else solve();
    return 0;
}
