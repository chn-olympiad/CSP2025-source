#include <bits/stdc++.h>
using namespace std;
const int max_=2e5+5;
int n,m,k,cnt,fa[max_];
bool is[max_];
struct node{
	int u,v,w,qwq;
}rp[max_];
int root(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=root(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		rp[++cnt].u=x;
		rp[cnt].v=y;
		rp[cnt].w=w;
	}
	for(int i=1;i<=k;i++){
		int _;
		cin>>_;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
		}
	}
	if(!k){
		sort(rp+1,rp+cnt+1,[&](node x,node y){
			return x.w<y.w;
		});
		int ans=0,qwq=0;
		for(int i=1;i<=cnt;i++){
			int rx=root(rp[i].u),ry=root(rp[i].v);
			if(rx^ry){
				fa[rx]=ry;
				ans+=rp[i].w;
				if((++qwq)==n-1){
					break;
				}
			}
		}
		cout<<ans<<'\n';
		exit(0);
	}
	cout<<0;
	return 0;
}
