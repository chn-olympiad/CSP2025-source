#include <bits/stdc++.h>
using namespace std;

namespace L1SkyL {
    void Main();
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    L1SkyL::Main();
    return 0;
}

namespace L1SkyL{
    int n,m,ans;
    int res[17];
    int vis[17];
    int c[17];
    int s[17];
    void dfs(int dep){
        //cout << dep << "\n";
        if (dep == n + 1){
            //cout << "hjm\n";
            int l = 0,fail = 0;
            for (int i = 1;i <= n;++i){
                if (fail >= c[res[i]] || s[i] == 0) ++fail;   
                else ++l;
                if (l >= m) {
                    ++ans;
                    return;
                }
            }
            return;
        }
        for (int i = 1;i <= n;++i){
            if (!vis[i]){
                res[dep] = i;
                vis[i] = 1;
                dfs(dep + 1);
                vis[i] = 0;
            }
        }
    }
    void Main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        int t;
        cin >> t;
        for (int i = 1;i <= n;++i){
            s[i] = t % 10;
            t /= 10;
            cin >> c[i];
            //cout << c[i] << "\n";
        }
        dfs(1);
        cout << ans << "\n";
    }
}