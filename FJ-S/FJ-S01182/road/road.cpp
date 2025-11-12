#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,c[15],a[15][10005];
struct edge{
	int u,v,w;
};
vector<edge> ed;
bool cmp(edge A,edge B){
	return A.w<B.w;
}
bool fl[10005],fla=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ed.push_back({u,v,w});
	}
	if(k==0){
		sort(ed.begin(),ed.end(),cmp);
		for(int i=0;i<ed.size();i++){
			if(fl[ed[i].u]&&fl[ed[i].v]) continue;
			ans+=ed[i].w;
			fl[ed[i].u]=1;
			fl[ed[i].v]=1;
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		bool flag=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(!a[i][j]) flag=1;
		}
		if(c[i]||!flag) fla=0;
	}
	if(fla){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(!a[i][j]){
					for(int l=1;l<=n;l++){
						if(l==j) continue;
						ed.push_back({j,l,a[i][l]});
					}
				}
			}
		}
		sort(ed.begin(),ed.end(),cmp);
		for(int i=0;i<ed.size();i++){
			if(fl[ed[i].u]&&fl[ed[i].v]) continue;
			ans+=ed[i].w;
			fl[ed[i].u]=1;
			fl[ed[i].v]=1;
		}
		printf("%d",ans);
		return 0;
	}
}