#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 998244353;
long long jiecheng(int x){
	long long res = 1;
	for(int i = 2 ; i <= x ; i++){
		res %= M;
		res *= i;
	}
	return res % M;
}
int c[N];
int p[N];
bool vis[10];
void solve(){
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool flag = true;
	
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '0'){
			flag = false;
			break;
		}
	}
	for(int i = 1 ; i <= n; i++) cin >> c[i];
	if(m == n){
		if(flag) cout << 1;
		else cout << 0;
		return;
	}
	if(m == 1){
		cout << jiecheng(n) % M;
		return;
	}
	if(flag){
		cout << jiecheng(n);
	}
	cout << 0;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
