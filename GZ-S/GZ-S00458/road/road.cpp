//CSP-S00458 贵阳1市第三实验中学 陈则睿 
//写一个kruskal拿20分走了 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,tot;
struct Edge{
	int u,v,w;
} e[6000000];
int fa[2000000],c[10][10010];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	cout<<"";//hyw,玄学这一块 
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int a,int b){
	int ga=find(a),gb=find(b);
	if(ga==gb)return ;
	fa[ga]=gb;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[tot].u=u;e[tot].v=v;e[tot].w=w;
		tot++;
	}
	for(int i=0;i<2000000;i++){fa[i]=i;}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			int w;scanf("%d",&w);
			c[i][j]=w;
		}
	}
	for(int m=0;m<k;m++){	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				e[tot].u=i;e[tot].v=j;e[tot].w=c[m][i]+c[m][j]+c[m][0];
				tot++;
			}
		}
	}
	sort(e,e+tot,cmp);
	int ans=0;
	for(int i=0;i<tot;i++){
		if(find(e[i].u)==find(e[i].v)){continue;}//已重复 
		ans+=e[i].w;
		merge(e[i].u,e[i].v);
	}
	cout<<ans;
	return 0;
} 
