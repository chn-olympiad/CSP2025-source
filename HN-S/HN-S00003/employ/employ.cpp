#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+100,mod=998244353;
int n,m,u;
string s;
int c[MAXN],vis[MAXN],ans;
void dfs(int x, int cnt, int o) {
    if (x==n+1) {
        u=cnt;
        //cout << ans << "\n";
        if (n-o-cnt>=m) {
            (ans+=1)%=mod;
        }
        return;
    }
    if (s[x]=='0') {
                dfs(x+1,cnt+1,o);
    } else {
        for (int i=1; i<=n; i++) {
            if (!vis[i]) {
                vis[i]=1;
                if (o+cnt>=c[i]) {
                    dfs(x+1,cnt,o+1);
                } else {
                    dfs(x+1,cnt,o);
                }
                vis[i]=0;
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> s;
	s=" " +s;
	for (int i=1; i<=n; i++) {
        cin >> c[i];
	}
	dfs(1,0,0);
	for (int i=1; i<=u; i++) {
        (ans*=i)%=mod;
	}
	cout << ans;
	return 0;
}
/*
dp[i][j]
*/
