#include<bits/stdc++.h>
#define ll long long
#define Mod 998244353
using namespace std;
string s;
ll n,m,a[510],f[510],ans=0;
// 第i个人排在第j位置 
bool vis[510];
ll checkf(){
	int tmp=0,fail=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')fail++;
		else{
			if(a[f[i]]<=fail)fail++;
			else tmp++;
		}
	}
	return tmp>=m;
}
ll dfs(int j){
	if(j>n){
		return checkf();
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i] = 1;
		f[j] = i;
		tmp+=dfs(j+1);
		tmp%=Mod;
		vis[i] = 0;
	}
	return tmp;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> s;s = " " +s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=20){
		cout << dfs(1) << endl;
		return 0;
	}
	if(m==1){ans=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans*=n-1;
			else ans *= n;
			ans %= Mod;
		}
		cout << ans << endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans *= a[i];
		ans %= Mod;
	}
	cout << ans<< endl;
	return 0;
}
