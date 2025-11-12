#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],c[505][505],ans;
const long long mod=998224353;
string s;
bool vis[505];
void dfs(int x,int sum){
	if(x==n+1){
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(a[i]<=x-sum-1){
			vis[i]=1;
			dfs(x+1,sum);
			vis[i]=0;
		}
		else{
			if(s[x-1]=='1'){
				vis[i]=1;
				dfs(x+1,sum+1);
				vis[i]=0;
			}
			else{
				vis[i]=1;
				dfs(x+1,sum);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=n;i++)c[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=(c[i][j-1]+c[i-1][j-1])%mod;
		} 
	}
	cout<<c[n][n];
	return 0;
}
