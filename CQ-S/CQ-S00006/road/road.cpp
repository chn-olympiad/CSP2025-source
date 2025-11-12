#include<bits/stdc++.h>
#define int  long long
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
	bool operator<(const node &o)const{
		return w<o.w;
	}
};
vector<node>e,ne,se[1050];
int sum[1050],tot[1050];
int fa[1000005],c[15],a[15][1000005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(auto x:e){
		int u=x.u,v=x.v,w=x.w;
		if(find(u)==find(v))continue;
		ne.push_back(x);
		int fu=find(u),fv=find(v);
		cnt++;
		fa[fu]=fv;
		if(cnt==n-1)break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ns=0;
	for(int msk=0;msk<(1<<k);msk++){
		for(auto x:ne)se[msk].push_back(x);
		tot[msk]=n;
		for(int i=1;i<=k;i++){
			if(msk&(1<<(i-1))){
				sum[msk]+=c[i];
				tot[msk]++;
				for(int j=1;j<=n;j++){
					se[msk].push_back({n+i,j,a[i][j]});
				}
			}
		}
		sort(se[msk].begin(),se[msk].end());
		ns+=se[msk].size();
	}
	int ans=1e18;
	for(int msk=0;msk<(1<<k);msk++){
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int cnt=0;
		for(auto x:se[msk]){
			int u=x.u,v=x.v,w=x.w;
			if(find(u)==find(v))continue;
			int fu=find(u),fv=find(v);
			fa[fu]=fv;
			cnt++;
			sum[msk]+=w;
			if(cnt==tot[msk]-1)break;
		}
		ans=min(ans,sum[msk]);
	}
	cout<<ans<<endl;
	return 0;
}

