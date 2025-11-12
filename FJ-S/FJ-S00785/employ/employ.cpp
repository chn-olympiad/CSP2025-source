#include <bits/stdc++.h> 
using namespace std;

const int MOD = 998224353;
int n, m, c[510], ans;
string s;
bool v[510];

void dfs(int k, int cc, int r){
	cout << k << " " << cc << " " << r << endl;
	if(r >= m){
		cout << "!!:" << k << " " << cc << " " << r << endl;
		ans++;
		return;
	}
	if(k > n){
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!v[i]){
			v[i] = 1;
			int b = 0;
			if(cc > c[i] || (s[k - 1] - '0') == 0){
				cc++;
				b = 1;
			}
			dfs(k + 1, cc, r + 1);
			v[i] = 0;
			if(b) cc--;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	
	return 0;
}
