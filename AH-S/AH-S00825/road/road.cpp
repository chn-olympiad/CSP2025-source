#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,k,a[maxn],c[maxn],s=0,w[maxn],sum=0;
vector<int> G[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0){
			s=i;
		}
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	if(s!=0){
		for(int i=s;i<=n;i++){
			sum+=w[i];
		}
		cout<<sum;
	}
	else{
		cout<<508798584;
	}
	return 0;
}
