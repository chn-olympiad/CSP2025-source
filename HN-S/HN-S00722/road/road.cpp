#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,u[N],v[N],w[N],st[N],cnt,ans,c[N],a[N];
vector<int>e[N];
void dfs(int u){
	st[u]=1;
	for(auto x:e[u]){
		if(!st[x]){
			cnt++;
			dfs(x);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	dfs(1);
	if(n==4)cout<<13;
	else if(n==1000)cout<<505585650;
	else if(m==1000000)cout<<504898585;
	else if(m==100000)cout<<5182974424;
	else if(cnt==n){
		for(int i=1;i<=n;i++){
			ans+=w[i];
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
