#include <bits/stdc++.h>
using namespace std;
int c[505];
int jie[505];
int v[505];
int cnt;
int dfs(int u, int n, int m, int ren, int wy){
	if (u >= n + 1){
		return 0;
	}if (wy >= m){
		cnt ++;
		//cout << cnt;
		cnt = cnt % 998244353;
		return cnt;
	}
	for (int i = u + 1; i <= n; i++){
		if (!v[i] && jie[i - 1] == 1 && c[i] > ren){
			v[i] = 1;
			dfs(i,n,m, ren,wy + 1);
			v[i] = 0;
		}else if (!v[i]){
			v[i] = 1;
			dfs(i,n,m, ren + 1,wy + 1);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.size();i++){
		if (s[i] == '1'){
			c[i] == 1;
		}else if (s[i] == '0'){
			c[i] == 0;
		}
	}
	for (int i = 1; i <= n;i++){
		cin >> c[i];
	}
	dfs(1, n, m, 0, 0);
	cout << cnt;
	return 0;
}
