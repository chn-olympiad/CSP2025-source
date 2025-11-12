#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int, int>;

int a[505], b[505];
int cho[505], used[505];int n, m; 

int MOD = 998244353;

int ans = 0;
void dfs(int step) {
    if(step == n + 1) {
        int cnt = 0, per = 0;
        for(int i = 1; i <= n; i ++) {
            if(per > m) {
                ans ++; return ;
            }
            if(b[cho[i]] <= cnt) cnt ++;
            else if(a[i] == 1) per ++;
            else cnt ++;
        }
        if(per >= m) ans ++;
        return ;
    }
    for(int i = 1; i <= n; i ++) {
        if(used[i] == 0) {
            used[i] = 1;
            cho[step] = i;
            dfs(step + 1);
            used[i] = 0;
        }
    }
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(0);
	 freopen("employ.in", "r", stdin);
	 freopen("employ.out", "w", stdout);
    cin >> n >> m;
    char ch;
    int flagO = 0, flagZ = 0;
    for(int i = 1; i <= n; i ++) {
    	cin >> ch;
		if(ch == '1') a[i] = 1, flagO ++;
		else a[i] = 0, flagZ ++;
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if(flagZ == 0) {
        if(m != n) {
            cout << 0 << "\n";
            return 0;
        }
    	int res = 1;
        for(int i = 1; i <= n; i ++) {
            res = res * i % MOD;
        }
        cout << res << "\n";
    	return 0;
    }else if(flagO == 0) {
        if(m == 0) {
            int res = 1;
            for(int i = 1; i <= n; i ++) {
                res = res * i % MOD;
            }
            cout << res << "\n";
            return 0;    
        } else cout << "0\n";
        return 0;
    } else if(n < 30) {
        dfs(1);
        cout << ans << "\n";
        return 0;
    } else {
    	if(m == n) {
            if(flagZ != 0) {
                cout << 0 << '\n';
                return 0;
            }
        }
        cout << "0\n";
    }
    
	return 0;
}

