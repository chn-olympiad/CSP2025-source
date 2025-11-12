#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
int cnt=1;
vector<node> ed;
int fa[10020],flag[15],val[15];
int vl[15][10020];
int _find(int x){
	if(fa[x]==x) return x;
	return fa[x]=_find(fa[x]);
}
void f(int x,int y){
	if(_find(x)==_find(y)) return ;
	fa[x]=y;
	return ;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int n,m,k,ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ed.push_back({u,v,w});
	}
	
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		val[i]=c;
		flag[i]=0;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			vl[i][j]=a;
		}
	}
	for(int i=0;i<=m;i++){
		int u=ed[i].u;
		int v=ed[i].v;
		for(int j=1;j<=k;j++){
			if(flag[j]==1) ed[i].w=min(ed[i].w,vl[j][u]+vl[j][v]);
			else ed[i].w=min(ed[i].w,vl[j][u]+vl[j][v]+val[j]),flag[j]=1;
		}
	}
	sort(ed.begin(),ed.end(),cmp);
	for(int i=0;i<m;i++){
		int u=ed[i].u;
		int v=ed[i].v;
		int w=ed[i].w;
		
		if(_find(u)==_find(v)) continue;
		
		f(u,v);
		ans+=w;
		cnt++;
		if(cnt==n) break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
