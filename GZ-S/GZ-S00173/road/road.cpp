//GZ-S000173 中央民族大学附属中学贵阳学校 张诗苑
#include<bits/stdc++.h>
using namespace std;
int n,m,k,e;
int g[10020],ki[1020];
long long ans;
struct B{
	int u,v,w;
}b[10000020];
int p[1020][1020]={-1};
bool cmp(B a,B b){
	return a.w<b.w;
}
int find(int x){
	if(g[x]==x) return x;
	g[x]=find(g[x]);
	return g[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
		
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) g[i]=i;

	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		p[min(u,v)][max(u,v)]=min(p[min(u,v)][max(u,v)],w);
		cout<<u<<" "<<v<<" "<<p[min(u,v)][max(u,v)]<<" "<<i<<endl;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++)
			scanf("%d",&ki[j]);
		for(int l=0;l<n;l++){
			for(int r=0;r<l;r++){
				if(p[l][r]==-1) p[r][l]=ki[l]+ki[r];
				else p[r][l]=min(ki[l]+ki[r],p[r][l]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(p[i][j]!=-1){
				b[e].u=i;
				b[e].v=j;
				b[e].w=p[i][j];
				e++;
			}
		}
	}
	sort(b,b+e,cmp);
	for(int i=0;i<e;i++){
		int u1=b[i].u,v1=b[i].v,w1=b[i].w;
		if(find(u1)!=find(v1)){
			ans+=w1;
			g[u1]=g[v1];
		}
	}
	printf("%d",ans);
	return 0;
}
