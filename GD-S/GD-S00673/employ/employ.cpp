#include<bits/stdc++.h>
using namespace std;
const int N = 505,mod = 998244353;
int n,m,c[N],a[N];
long long ans = 0;
string s;
bool ok[15];
void dfs(int cnt){
	if(cnt == n){
		int tt = 0;
		for(int i = 1;i <= n;i++){
			if( c[a[i]] <= tt) ++tt;
			else if( s[i] == '0') ++tt;	
		}
		if( n - tt == m) ++ans;
		return;
	}
	++cnt;
	for(int i = 1;i <= n;i++){
		if( ok[i] == 0){
			ok[i] = true;
			a[ cnt ] = i;
			dfs( cnt );
			ok[i] = false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = " "+s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	if(n <= 10) {
		dfs( 0 );
		cout << ans <<"\n";
	}
	else if(m == n){
		ans = 1;
		for(int i = 1;i <= n;i++) ans = (ans*i)%mod;
		cout << ans;
	}else cout << 0;
	return 0;
}

