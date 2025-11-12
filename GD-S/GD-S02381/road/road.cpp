# include<cmath>
# include<cstdio>
# include<cstring>
# include<iostream>
# include<algorithm>
# define I inline int
# define V inline void
# define ll long long
const int N=1e4+5,M=4e6+10;
using namespace std;
int n,m,k,ans,em;
int map[15][N],c[N];
int fa[N],siz[N];
int to[M],fr[M],ls[N],nx[M],vl[M];
struct Node{
	int to1,fr1,vl1;
}edg[M];
V add(int x,int y,int z) {
	to[++em]=y,fr[em]=x,nx[em]=ls[x],ls[x]=em;
	vl[em]=z;
	return ;
}
bool cmp(Node x,Node y) {
	return x.vl1<y.vl1;
}
I find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
}
V link(int x,int y) {
	int xx=find(x),yy=find(y);
	fa[yy]=xx;
	siz[xx]+=siz[yy];
	return ; 
}
int main() {
	//注意区分乡镇和城市 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); 
	}
	for(int i=1;i<=k;i++) {
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	if(k==0) {
		ll res=0;
		for(int i=1;i<=em;i++) {
			edg[i]=(Node){to[i],fr[i],vl[i]};
		}
		for(int i=1;i<=n;i++) fa[i]=i,siz[i]=0;
		sort(edg+1,edg+1+em,cmp);
		for(int i=1;i<=em;i++) {
			if(siz[find(1)]==n) break;
			int x=edg[i].fr1,y=edg[i].to1;
			if(find(x)!=find(y)) {
				link(x,y);
				res+=edg[i].vl1;
			}
		}
		printf("%lld\n",res);
	} 
	/*
	for(int S=0;S<1<<k;S++) {
		//反着编号 
		int oem=em;
		ll res=0;
		for(int i=1;i<=k;i++) {
			if(S>>(i-1)&1) {
				for(int j=1;j<=n;j++) {
					add(c[i],map[i][j]);
				}
				res+=
			}
		}
		//最小生成树 
		for(int i=1;i<=em;i++) {
			edg[i]=(Node){to[i],fr[i],vl[i]};
		}
		for(int i=1;i<=n;i++) fa[i]=i,siz[i]=0;
		sort(edg+1,edg+1+em,cmp);
		for(int i=1;i<=em;i++) {
			if(siz[find(1)]==n) break;
			int x=edg[i].fr1,y=edg[i].to1;
			if(find(x)!=find(y)) {
				link(x,y);
				res+=edg[i].vl1;
			}
		}
		ans=min(ans,res);
	}
	*/
	return 0;
}
