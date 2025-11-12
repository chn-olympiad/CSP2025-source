#include <bits/stdc++.h>
#define int long long
using namespace std;
struct tututu{
	int u,v,w;
}edge[2000005]; 
int fa[20005];
int n,m,k;
int cnt=0;
int find(int x){
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(tututu a,tututu b) {
	return a.w<b.w;
}
inline void uni(int a,int b){
	fa[find(a)]=find(b);
}
int ans=0;
bool judge(){
	int tfa=find(1);
	for (int i=2;i<=n;i++){
		if (find(i) != tfa) return 0;
	}
	return 1;
}
int cnt1=0;
void kru(){
	sort(edge+1,edge+cnt+1,cmp);
	for (int i=1;i<=cnt;i++){
		
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if (find(u) != find(v)) {
			uni(u,v);
			
			ans+=w;
			cnt1++;
			if (judge()) {
				cout<<ans;
				exit(0);
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if (1){
		for (int i=1;i<=n;i++)fa[i]=i;
		for (int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			edge[++cnt]={u,v,w};
		}
		kru();
}
//	}else {
//		for(int i=1;i<=n+1;i++) fa[i]=i;
//		for (int i=1;i<=m;i++){
//			int u,v,w;
//			cin>>u>>v>>w;
//			edge[++cnt]={u,v,w};
//		}
//		vector<int> jr(n);;
//		for (int i=1;i<=k;i++){
//			int c;cin>>c;
//			for (int j=1;j<=n;j++) cin>>jr[i];
//			for (int u=1;u<=n;u++){
//				for (int v=1;v<=n;v++){
//					edge[++cnt]={u,v,jr[u]+jr[v]};
//				}
//			}
//		}
//		cout<<cnt;
//		kru();
//	}
	
	return 0;
}
