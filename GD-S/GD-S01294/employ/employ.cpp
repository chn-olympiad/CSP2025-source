#include <bits/stdc++.h>
using namespace std;
const int N = 500;
const int mod = 998244353;
int n,m;
string s;
int c[N];
long long pi[N];
long long ans;
bool vis[19];
int per[19];
void dfs(int x){
	if(x == n + 1){
		int lft = 0;
		for(int i = 1;i <= n;i++){
			//cout << per[i] << ' ';
			if(lft >= c[per[i]] || s[i - 1] == '0'){
				lft++;
			}
		}
		//cout << endl;
		if(n - lft >= m) ans++;
	}
	else{
		for(int i = 1;i <= n;i++){
			if(vis[i]) continue;
			per[x] = i;
			vis[i] = true;
			dfs(x + 1);
			per[x] = 0;
			vis[i] = false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	pi[0] = 1;
	for(int i = 1;i < N;i++){
		pi[i] = (pi[i - 1] * i) % mod;
	}
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	sort(c + 1,c + n + 1);
	if(n <= 18){
		//cout << 'a' << endl;
		dfs(1);
		cout << ans << endl;
		return 0;
	}
	if(m == 1){
		int tmp = 0;
		for(int i = 0;i < s.size();i++){
			if(s[i] == '1'){
				tmp = i + 1;
				break;
			}
		}
		int tmp2 = n;
		for(int i = 1;i <= n;i++){
			if(c[i] >= tmp){
				tmp2 = i;
				break;
			}
		}
		long long ans = 1;
		ans = ((n - (tmp2 - 1)) * pi[n - 1] % mod);
		cout << ans << endl;
		return 0;
	}
	else if(m == n){
		bool f1 = 1;
		for(int i = 0;i < s.size();i++){
			if(s[i] == '0') f1 = 0;
		}
		if(f1){
			cout << pi[n] << endl;
			return 0;
		}
		else{
			cout << 0 << endl;
			return 0;
		}
	}
	bool fb = 1;//льепA 
	int cnt = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] == '0'){
			fb = false;
		}
		else{
			cnt++;
		}
	}
	if(fb = true){
		//cout << 'ab';
		cout << pi[n] << endl;
		return 0;
	}
	if(cnt < m){
		cout << 0 << endl;
		return 0;
	}
	cout << pi[n];
	
	return 0;
} 
