#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fa[10025],n,m,k,tp[15];
ll c[15],ans=LONG_LONG_MAX;
int find(int u){return (fa[u]?fa[u]=find(fa[u]):u);}
struct E{
	ll u,v,w;
	bool operator<(const E& b)const{
		return w<b.w;
	}
}all[1000005];
vector<E> edge[15];
ll getans(int zt){
	ll re=0,ppc=0;
	memset(fa,0,sizeof(fa));
	memset(tp,0,sizeof(tp));
	for(int i=1;i<=k;i++)if((zt>>(i-1))&1){
		re+=c[i];
		ppc++;
	}
	for(int cnt=0;cnt<n+ppc-1;){
		int mn=-1;
		for(int i=0;i<=k;i++)if(((zt>>(i-1))&1)||i==0){
			if(tp[i]<edge[i].size()){
				if(mn==-1)mn=i;
				else if(edge[i][tp[i]]<edge[mn][tp[mn]])mn=i;
			}
		}
		if(find(edge[mn][tp[mn]].u)!=find(edge[mn][tp[mn]].v)){
			re+=edge[mn][tp[mn]].w;
			fa[find(edge[mn][tp[mn]].u)]=find(edge[mn][tp[mn]].v);
			cnt++;
		}
		tp[mn]++;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>all[i].u>>all[i].v>>all[i].w;
	sort(all+1,all+1+m);
	for(int i=1,cnt=0;i<=m;i++){
		if(cnt==n-1)break;
		if(find(all[i].u)!=find(all[i].v)){
			edge[0].push_back(all[i]);
			fa[find(all[i].u)]=find(all[i].v);
			cnt++;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			ll w;
			cin>>w;
			edge[i].push_back({(ll)j,(ll)n+i,w});
		}
		sort(edge[i].begin(),edge[i].end());
	}
	for(int i=0;i<(1<<k);i++)ans=min(ans,getans(i));
	cout<<ans;
}

