#include<bits/stdc++.h>
using namespace std;
int n, m, c[550], cnt=0;
string s;
map<string, bool> mp;
bool vis[550];
void dfs(int dep, int emp, int fal, string sta){
	if(emp>=m&&!mp[sta]){
		cnt++;
		mp[sta]=1;
	}
	if(dep>n)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(fal>=c[i]){
			vis[i]=1;dfs(dep+1, emp, fal+1, (char)(i)+sta); vis[i]=0;
			continue;
		}
		if(s[dep]){
			vis[i]=1;dfs(dep+1, emp, fal+1, (char)(i)+sta); vis[i]=0;
		}
		if(!s[dep]){
			vis[i]=1;dfs(dep+1, emp+1, fal, (char)(i)+sta); vis[i]=0;
		}		
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	dfs(0,0,0,"");
	cout << cnt;
	return 0;
}
