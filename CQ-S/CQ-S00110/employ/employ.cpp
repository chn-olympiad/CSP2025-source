#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
bool v[500];
long long cnt;
void dfs(int x,int y,int ans){
	if(y==0){
		cnt++;
		cnt%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		if(c[i]<=ans||s[x-1]=='0') dfs(x+1,y,ans+1);
		else dfs(x+1,y-1,ans);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=m){
		cout<<0;
		return 0;
	}
	dfs(1,m,0);
	cout<<cnt;
	return 0;
}
