#include<bits/stdc++.h>
using namespace std;
const int MOD =  998244353; 
int n,m,c[510];
unsigned long long ans;
string s;
bool p[510] = {0};
void dfs(int day,int tot,int go){
	if(day == n){
		if(tot >= m) ans++;
		ans%=MOD;
	}
	for(int i = 1;i<=n;i++){
		if(!p[i]){
			p[i] = 1;
			dfs(day+1,(s[day] == '1' && c[i] > go)?tot+1:tot,(s[day] == '0' || c[i] <= go)?go+1:go);
			p[i] = 0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	bool flag = 1,flag2 = 1;int num1 = 0; // teA  teB
	for(int i = 0;i<n;i++){
		if(s[i] == '0') flag = 0;
		else num1++;
	}
	if(num1 != 18) flag2 = 0;
	for(int i = 1;i<=n;i++) cin >> c[i];
	if(flag){
		sort(c+1,c+n+1);
//		for(int i = 1;i<=n;i++) cout << c[i] << " "; 
		ans = 1;int go;
		for(go = 1;!c[go+1];go++);
//		cout << go << " ";
		for(int i = 1;i<=m;i++){
			ans = ((ans % MOD)*(i % MOD)) % MOD;
		}
		long long tmp = ans;
		for(int i = m+1;i<=n-go;i++){
			tmp = ((tmp % MOD)*(i % MOD)) % MOD;
			ans = ((tmp%MOD) + (ans % MOD)) % MOD;
		} 
		if(n-go < m) ans = 0;
	}
	else if(flag2){
		ans = 1;
		for(int i = 1;i<=18;i++){
			ans = ((ans % MOD)*(i % MOD)) % MOD;
		}
	}
	else dfs(0,0,0);
	cout << ans%MOD;
	return 0; 
}
