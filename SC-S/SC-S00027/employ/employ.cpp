#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int c[505];
int a[15];
int vis[15];
int n,m;
string s;
long long ans;
bool check(){
	int sum = 0;
	for(int i=1; i<=n; i++){
		if(c[a[i]]>(i-1)-sum&&s[i-1]=='1') sum++;
	}
	return sum>=m;
}
void dfs(int x){
	if(x>n){
		if(check()) ans = (ans+1)%mod;
		return;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			a[x] = i;
			vis[i] = 1;
			dfs(x+1);
			vis[i] = 0;
		}
	}
}
int main(){
	//8pts
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i=1; i<=n; i++){
		cin >> c[i];
	}
	if(n<=10){
		dfs(1);
		cout << ans;
	}else{
		
	}
	return 0;
} 