#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[101],pl[101];
bool vis[101];
int s1[101];
int ans = 0;
bool check(){
	int sum = 0,tt = 0;
	for(int i = 1;i<=n;i++){
		if(tt>=c[pl[i]]){
			tt++;
			continue;
		}
		else if(s1[i]){
			sum++;
		}
		else{
			tt++;
		}
	}
	return sum>=m;
}
void dfs(int st){
	if(st == n+1){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			pl[st] = i;
			dfs(st+1);
			vis[i] = 0;
			pl[st] = 0;
		}

	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		s1[i] = s[i-1]-'0';
	}
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
