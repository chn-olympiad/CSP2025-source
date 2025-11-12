#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m,k,vis[11],fa[N],cntp[11],c[11],tot;
long long ans;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int rx=find(x),ry=find(y);
	fa[rx]=ry;
}
struct node{
	int u,v,w;
	bool operator<(const node &b){
		return w<b.w;
	}
}p[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		p[++tot]=node{u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			p[++tot]=node{i+n,j,w};
		}
	}
	sort(p+1,p+tot+1);
	int cnt=0;
	for(int i=1;i<=tot;i++){
		int u=p[i].u,v=p[i].v,w=p[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
			cnt++;
			//cout<<u<<"*"<<v<<endl;
		}
		if(cnt>=n+k-1) break;
	}
	//cout<<cnt<<"&\n";
	cout<<ans;
}
