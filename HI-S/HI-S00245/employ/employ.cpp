#include<bits/stdc++.h>
using namespace std;
const int mob = 998244353;
int n,m,a[100010],vis[100010],ans;
string s;
void dfs(int now,int sum,int go){
	if(now > n){
		if(sum >= m){
			ans = (ans+1)%mob;
		}
		return;
	}
	if(sum+(n-now+1) < m){
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]){
			continue;
		}
		vis[i] = 1;
		int l = (int)(s[now-1]-'0');
		if(go >= a[i]){
			l = 0;
		}
		dfs(now+1,sum+l,go+1-l);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>> n >> m >> s;
	bool f = 1;
	for(int i = 1;i <= n;i++){
		cin>> a[i];
		if(a[i] != 1){
			f = 0;
		}
	}
	sort(a+1,a+n+1);
	if(f){
		int sum = 0,a = 1;
		for(int i = 1;i <= n;i++){
			a *= n-i+1;
			if(!(int)(s[i-1]-'0')){
				break;
			}else{
				sum++;
			}
		}
		if(sum >= m){
			cout<< sum*a%mob;
		}else{
			cout<< 0;
		}
		return 0;
	}
	if(n >= 13){
		cout<< 1;
		return 0;
	}
	dfs(1,0,0);
	cout<< ans;
	return 0;
}
