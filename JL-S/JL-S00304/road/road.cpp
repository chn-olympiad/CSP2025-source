#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
}e[3000006];
int fa[10004];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int get_fa(int u){
	return (fa[u]==u?u:fa[u]=get_fa(fa[u]));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	int tot=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++tot].u=u;
		e[tot].v=v;
		e[tot].w=w;
	}
	if(k!=0){
		int a[10];
		for(int i=k+1;i<=2*k;i++){
			a[i]=1;
		}
		int maxx=-1;
		do{
			int cntt=0;
			for(int i=1;i<=k;i++){
				int k;
				cin>>k;
				if(a[i]==1){
					for(int j=1;j<=n;j++){
						e[++tot].u=i;
						e[tot].v=j;
						int hhh;
						cin>>hhh;
						e[tot].w=hhh;
					}
					cntt+=k;
				}
				else{
					for(int j=1;j<=n;j++){
					int hhh;
					cin>>hhh;
				}
				}
			}
			sort(e+1,e+tot+1,cmp);
			int ans=0;
			for(int i=1;i<=tot;i++){
				int uu=get_fa(e[i].u);
				int vv=get_fa(e[i].v);
				if(uu!=vv){
					fa[uu]=vv;
					ans+=e[i].w;
				}
			}
			maxx=max(ans,maxx);
		}while(next_permutation(a+1,a+k+k+1));
		cout<<maxx;
	}
	sort(e+1,e+tot+1,cmp);
	int ans=0;
	for(int i=1;i<=tot;i++){
		int uu=get_fa(e[i].u);
		int vv=get_fa(e[i].v);
		if(uu!=vv){
			fa[uu]=vv;
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}