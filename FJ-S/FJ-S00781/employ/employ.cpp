#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int a[505];
int dis[505];
bool vis[505];
long long ans=0;
void check(){
	int h=0;
	int y=0;
	for(int i=1;i<=n;i++){
		int p=int(s[i-1]-'0');
		if(h>=dis[i])h++;
		else{
			if(p==0)h++;
			if(p==1)y++;
		}
	}
	if(y>=m)ans++;
	ans%=998244353;
}
void dfs(int t){
	if(t>n){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dis[t]=a[i];
			dfs(t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
10 5 
1101111011 
6 0 4 2 1 2 5 4 3 3 

*/
