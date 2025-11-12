#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<pair<long long,long long>> a[10015];
long long x[10015];
long long y[15];
bool b[10015];
long long MIN=99999999;
void dfs(long long x,long long l,long long s){
	if (x>n){
		s+=y[x-n];
	}
	if (s>=MIN){
		return;
	}
	if (l>=n){
		MIN=min(MIN,s);
		return;
	}
	for(long long i=0;i<a[x].size();i++){
		if (b[a[x][i].first]==false){
			b[a[x][i].first]=true;
			if (a[x][i].first>n) dfs(a[x][i].first,l,s+a[x][i].second); 
			else dfs(a[x][i].first,l+1,s+a[x][i].second); 
			b[a[x][i].first]=false;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin>>n>>m>>k;
	scanf("%lld %lld %lld",&n,&m,&k);
	long long u,v,w;
	for(long long i=1;i<=m;i++){
//		cin>>u>>v>>w;
		scanf("%lld %lld %lld",&u,&v,&w);
		a[u].push_back(make_pair(v,w));
		a[v].push_back(make_pair(u,w));
	}
	for(long long i=1;i<=k;i++){
//		cin>>w;
		scanf("%lld",&y[i]);
		for(long long j=1;j<=n;j++){
//			cin>>x[j];
			scanf("%lld",&x[j]);
		}
		for(long long j=1;j<=n;j++){
			a[j].push_back(make_pair(i+n,x[j]));
			a[i+n].push_back(make_pair(j,x[j]));
		}
	}
//	for(long long i=1;i<=n+k;i++){
//		for(long long j=0;j<a[i].size();j++){
//			cout<<i<<' '<<a[i][j].first<<' '<<a[i][j].second<<endl;
//		}
//	}
	dfs(1,1,0);
	for(long long i=1;i<=n+k;i++){
		for(long long j=1;j<=n+k;j++){
			b[i]=false;
		}
		b[i]=true;
		dfs(i,1,0);
	}
	cout<<MIN;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
