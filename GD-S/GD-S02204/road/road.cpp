#include<bits/stdc++.h>
using namespace std;
#define int long long
using Vi=vector<int>; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=INT_MAX;
	cin>>n>>m>>k;
	using node=array<int,3>; 
	vector<node>E; 
	Vi C(k+1),F(n+k+1);
	for(int i=1,u,v,w;i<=m and cin>>u>>v>>w;i++)
		E.push_back({u,v,w});
	for(int i=1;i<=k and cin>>C[i];i++)
		for(int j=1,w;j<=n and cin>>w;j++)
			E.push_back({n+i,j,w});
	sort(E.begin(),E.end(),[](node x,node y){
		return x[2]<y[2];	
	});
	function<int(int)>find=[&](int u){
		return u==F[u]?u:F[u]=find(F[u]);
	};
	for(int S=0;S<(1<<k);S++){
		int sum=0,cnt=0;
		bitset<11>bits(S);
		for(int u=0;u<k;u++)
			if(bits[u])sum+=C[u+1];
		//O(n)求取最小生成树？
		for(int i=1;i<=n+k;i++)F[i]=i;
		for(auto p:E){
			int u=p[0],v=p[1],w=p[2];
			if(u>n and !bits[u-n-1])
				continue;//不在点集之内 
			u=find(u);v=find(v);
			if(u==v)continue;
			F[u]=v;sum+=w;cnt++;
			if(cnt==n+bits.count()-1)break;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	/*
		发现k最多只有10，启发我们使用O(n2^k)的算法。 
		先把O(m2^k)的暴力打了吧~ 
		发现需要一种方法使求MST时无需重排边，
		此时时间将下降为O((n+k-1)*2^k).
		
		青史留墨十万卷，长髯映雪千里行！ 
	*/
	return 0;
} 
