#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c[11];
struct edges{
	int u,v;
	ll w;
	int f;
	bool operator<(const edges& o)const{
		return w<o.w;
	}
};
const int N = 1e4+5;
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	vector<edges>r;
	r.reserve(m+k*n);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		r.push_back({u,v,w,0});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		vector<ll>a(n+1);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				r.push_back({u,v,a[u]+a[v],i});
	}
	int cnt=0;
	ll res=4e18;
	sort(r.begin(),r.end());
	for(int s=0;s<(1<<k);s++){
		vector<bool>flag(k+1,0);
		flag[0]=1;
		ll cur=0;
		cnt=0;
		for(int j=0;j<k;j++)
			if(s&(1<<j))
				cur+=c[j+1],flag[j+1]=1;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=0;i<r.size();i++){
			
			if(flag[r[i].f]==0)
				continue;
			int u=r[i].u,v=r[i].v;
			ll w=r[i].w;
			u=find(u),v=find(v);
			if(u!=v){
				fa[u]=v;
				cur+=w;
				if(++cnt>n-2){
					res=min(res,cur);
					break;
				}
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}