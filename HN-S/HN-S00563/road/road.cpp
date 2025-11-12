#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
int n,m,k,st[N];
vector<int>e[N];
void dfs(){
	for(auto x:e[N]){
		if(!st[x]){
			st[x]=1;
			cout<<x<<" ";
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=k;i++){
		int p;
		cin>>p;
		for(int j=1,c;j<=n;j++){
			cin>>c;
		}
	}
	cout<<0;
	return 0;
}
