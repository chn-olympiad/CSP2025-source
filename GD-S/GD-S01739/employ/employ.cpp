#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 4, MOD = 998244353;
int n,m,c[N],ans,tot;
string s;
bool f[N];
void dfs(int x,int b){
	if(x == n){
		if(b >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!f[i]){
			f[i] = 1;
			if(tot >= c[i] || s[x] == '0'){
				tot++;
				dfs(x+1,b);
				tot--;
			}
			else dfs(x+1,b+1);
			f[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dfs(0,0);
	cout << ans;
	return 0;
} 
