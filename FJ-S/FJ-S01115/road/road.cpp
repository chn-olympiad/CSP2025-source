#include<bits/stdc++.h>
using namespace std;
int n,m,k;
//struct node{
//	int v,w;
//	operator>(const node x){
//		if(w==x.w) return v<x.v;
//		return w<x.w;
//	}
//};
//vector<node> e[10005];
//priority_queue<node,vector<int>,greater<int> > q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
//		e[u].push_back({v,w});
//		e[v].push_back({u,w});
	}
	long long ans=1e18;
	for(int i=1;i<=k;i++){
		long long sum=0;
		for(int j=0;j<=n;j++){
			long long x;
			scanf("%lld",&x);
			sum+=x;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
