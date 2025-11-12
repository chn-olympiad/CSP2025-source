#include <bits/stdc++.h>
#define lint long long
#define endl '\n'
using namespace std;
const int N = 5e2+5;
const int P = 998244353;

int n,m,c[N];
bool s[N];
string s1;
int a[N];
bool b[N];
lint ans;

inline void dfs(int x){
	if(x > n){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(!s[i] || cnt >= c[a[i]])
				cnt++;
		}
		if(n-cnt >= m) ans++;
		ans %= P;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(b[i]) continue;
		b[i] = true;
		a[x] = i;
		dfs(x+1);
		b[i] = false;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin >> n >> m >> s1;
	for(int i = 0; i < n; i++)
		s[i+1] = (s1[i] == '1');
	for(int i = 1; i <= n; i++)
		cin >> c[i];
		
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += s[i];
	
	if(cnt == n){
		ans = 1;
		for(int i = 1; i <= n; i++)
			ans = (ans * i) % P;
		cout << ans << endl;
		return 0;
	}
	
	dfs(1);
	
	cout << ans << endl;
	return 0;
}
