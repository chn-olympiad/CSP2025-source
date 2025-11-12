#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}e[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
struct edge{
	int sh,id;
}c3[15];
int c[15][10005];
node c2[15][10000005];
int tot[15];
int val[15];
int fa[10005];

int getfa(int x){
	if(x!=fa[x]){
		return fa[x]=getfa(fa[x]);
	}
	return x;
}
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	fa[x]=y;
	return ;
}
long long ans=0;
bool cmp2(edge x,edge y){
	return (x.sh-val[x.id])>(y.sh-val[y.id]);
}
void kusk(){
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v,w=e[i].w;
		if(getfa(u)==getfa(v)){
			continue;
		}
		ans+=w;
		merge(u,v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e[i]={u,v,w};
	}
	
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
		for(int j=1;j<=n;j++){
			for(int p=1;p<=n;p++){
				e[++m]={j,p,c[i][j]+c[j][p]};
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	kusk();
	cout<<ans;
	return 0;
}
