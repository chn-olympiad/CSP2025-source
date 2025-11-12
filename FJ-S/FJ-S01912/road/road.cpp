#include<bits/stdc++.h>
using namespace std;
vector<int> q[10005];
int n,m,k,ans,a[10005];
int dfs(int p,int f){
	if(p==f)return p+3;
	if(a[p]==1)return p+2;
	a[p]=1;
	int s=0;
	for(int i=1;i<=q[p].size()/2;i++){
		s=max(dfs(q[p][2*i-2],f),s);
	}
	return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q[u].push_back(v);
		q[u].push_back(w);
		q[v].push_back(u);
		q[v].push_back(w);
	}
	for(int i=1;i<=n;i++){
		ans+=dfs(1,i); 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
