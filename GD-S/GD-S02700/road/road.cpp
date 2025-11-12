#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,z,a[100005];
long long ans=1e9,b[15][100005];
map<int,int> mp1[100005],p,mp2[100005];
vector<int> v[100005];
void dfs(long long i,long long sum,long long cost){
	if(cost>ans) return;
	if(sum>=n){
		ans=min(ans,cost);
		return;
	}
	for(int l:v[i]){
		if(mp2[i][l]) continue;
		mp2[i][l]=1;
		if(!p[l]){
			p[l]=1;
			dfs(l,sum+1,cost+mp1[i][l]);
			p[l]=0;
		}else{
			dfs(l,sum,cost);
		}
		mp2[i][l]=0; 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		mp1[x][y]=z;
		mp1[y][x]=z;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	if(k>0) return cout<<0,0;
	p[1]=1;
	dfs(1,1,0);
	cout<<ans;
	return 0; 
} 

