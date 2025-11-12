#include<bits/stdc++.h>
using namespace std;
const int N=20010,M=1000010;
typedef long long LL;
struct edge{
	int u,v,w;
}e[M],e1[M],e2[M*2];
int a[20][N],c[20],cnt;
int n,m,k,s;
int fa[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
LL kruskal(){
	LL res=0;
	for(int i=1;i<=s;i++){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		int u=e2[i].u,v=e2[i].v,w=e2[i].w;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			res+=w;
			fa[fx]=fy;
		}
	}
	return res;
}
int count(int x){
	int res=0;
	while(x){
		res+=(x&1);
		x>>=1;
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	LL ans=1e18;
	sort(e+1,e+1+m,cmp);
	for(int i=0;i<(1<<k);i++){
		LL res=0;
		int cnt2=0;
		s=n;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				s++;
				res+=c[j];
				for(int l=1;l<=n;l++){
					e1[++cnt2]={s,l,a[j][l]};
				}
			}
		}
		sort(e1+1,e1+1+cnt2,cmp);
		int p=1,q=1;
		cnt=0;
		while(p<=m&&q<=cnt2){
			if(e[p].w<e1[q].w)e2[++cnt]=e[p++];
			else e2[++cnt]=e1[q++];
		}
		while(p<=m){
			e2[++cnt]=e[p++];
		}
		while(q<=cnt2){
			e2[++cnt]=e1[q++];
		} 
		res+=kruskal();
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
