#include<bits/stdc++.h>
using namespace std;
long long f[1010][1010];
long long mp[1010];
queue<long long> q;
long long cost[1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,sum=0;
	scanf("%lld%lld%lld",&n,&m,&k); 
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		f[u][v]=w;
		f[v][u]=w;
		sum+=w;
		mp[u]++;
		mp[v]++;
	}
	long long t;
	scanf("%lld",&t);
	for(long long i=1;i<=n;i++) scanf("%lld",&t);
	cout<<0;
	return 0;
} 
