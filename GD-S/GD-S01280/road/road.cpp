#include <bits/stdc++.h>
using namespace std;
int n,m,k,idx,ans,ans1,ans2,fa[11451];
bool f;
struct edge{
	int u,v,w;
}e[1145141];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[++idx]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		int c[11451];
		cin >> c[0];
		for(int i=1;i<=n;i++)cin >> c[i];
		if(c[0]==0){
			for(int j=1;j<n;j++)for(int o=j+1;o<=n;o++)e[++idx]={j,o,c[j]+c[o]};
			f=1;
		}
	}
	if(f||k==0){
		sort(e+1,e+idx+1,cmp);
		for(int i=1;i<=idx;i++){
			edge tmp=e[i];
			if(find(tmp.u)!=find(tmp.v)){
				ans+=tmp.w;
				fa[find(tmp.v)]=find(tmp.u);
			}
		}
		cout << ans;
	}else{
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			edge tmp=e[i];
			if(find(tmp.u)!=find(tmp.v)){
				ans2+=tmp.w;
				fa[find(tmp.v)]=find(tmp.u);
			}
		}
		cout << ans2;
	}
}

