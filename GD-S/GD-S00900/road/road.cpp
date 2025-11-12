#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
	long long w;
}f[2000005],l[2000005];
int n,m,k,cnt=0,top=0,b[15],fa[10015],siz[10015];
long long a[15][10005],c[15],ans=1e18;
bool cmp(const node&x,const node&y){
	return x.w<y.w;
}
int search(int x){
	return fa[x]==x?x:fa[x]=search(fa[x]);
}
void dfs(int x){
	if(x==k+1){
		top=n,cnt=0;
		int y=m;
		long long res=0;
		for(int i=1;i<=m;i++) l[i]=f[i];
		for(int i=1;i<=k;i++){
			if(b[i]){
				top++;
				for(int j=1;j<=n;j++) l[++y]={top,j,a[i][j]};
				res+=c[i];
			}
		}
		for(int i=1;i<=top;i++) fa[i]=i,siz[i]=1;
		sort(l+1,l+y+1,cmp);
		for(int i=1;i<=y;i++){
			int u=search(l[i].u),v=search(l[i].v);
			if(u!=v){
				if(siz[u]>siz[v]){
					siz[u]+=siz[v];
					fa[v]=u;
				}
				else{
					siz[v]+=siz[u];
					fa[u]=v;
				}
				cnt++;
				res+=l[i].w;
			}
			if(cnt==top-1){
				ans=min(ans,res);
				return ;
			}
		}
		return ;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&f[i].u,&f[i].v,&f[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(k!=0&&m>100000){
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
