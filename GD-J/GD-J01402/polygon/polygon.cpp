#include<bits/stdc++.h>
using namespace std;
#define int long long
#define umap unordered_map
const int M=998244353;
const int N=5005;
umap<int,umap<int,umap<int,int> > > dp;
int n,a[N],ans=0;
int dfs(int x,int y,int z){
	if(x>n) return 0;
	if(dp[x][y][z])
		return dp[x][y][z];
	if(y>a[x]&&z>=2) dp[x][y][z]++;
	dp[x][y][z]=(dp[x][y][z]+dfs(x+1,y,z)+dfs(x+1,y+a[x],z+1))%M;
	return dp[x][y][z];
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if((n>=21&&maxn!=1)||n>500){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<dfs(1,0,0);
	return 0;
}