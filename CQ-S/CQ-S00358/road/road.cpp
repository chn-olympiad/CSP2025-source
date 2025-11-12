#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100010;
struct Node{
	int u,v,w;
	bool operator <(const Node t)const{
		return t.w>w;
	}
}edge[N],eg[N];
int val[N],g[12][100010];
int fa[100010];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++)cin>>g[i][j];
	}
	int minn=1e18;
	for(int st=0;st<(1<<k);st++){
		int ans=0,cnt=m;
		for(int i=1;i<=m;i++)eg[i]=edge[i];
		int ggg=n;
		for(int i=0;i<k;i++){
			if(st&(1<<i)){
				ggg++;
				ans+=val[i];
				for(int j=1;j<=n;j++){
					eg[++cnt]={ggg,j,g[i][j]};
				}
			}
		}
//		cout<<st<<":--"<<ans<<endl;
		sort(eg+1,eg+1+cnt);
//		for(int i=1;i<=cnt;i++)cout<<eg[i].u<<" "<<eg[i].v<<" "<<eg[i].w<<endl;
		for(int i=0;i<=ggg;i++)fa[i]=i;
		int num=0;
		for(int i=1;i<=cnt;i++){
			int u=eg[i].u,v=eg[i].v;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
//				cout<<i<<endl;
				fa[fv]=fu;
				ans+=eg[i].w;
				if(++num==ggg-1)break;
			}
		}
//		cout<<st<<":"<<ans<<endl;
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}
