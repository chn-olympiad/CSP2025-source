#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int mzk=2e6+5;
struct node{
	int u,v,w;
}e[mzk];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[10005];
int c[15],len[15][10005];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void uni(int x,int y){
	fa[find(x)]=find(y);
	return;
}
int tot;
int kruscal(){
//	for(int i=1;i<=n;i++){
//		fa[i]=i;
//	}
	sort(e+1,e+1+tot,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=tot;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		uni(e[i].u,e[i].v);
		ans+=e[i].w;
		++cnt;if(cnt==n-1) break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		++tot;
		scanf("%lld %lld %lld",&e[tot].u,&e[tot].v,&e[tot].w);
	}
	if(!k){
		printf("%lld",kruscal());
		return 0;
	}
	int rin=1;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) rin=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&len[i][j]);
		}
	}
	if(rin){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					e[++tot].u=j,e[tot].v=k;
					e[tot].w=len[i][j]+len[i][k];
				}
			}
		}
		printf("%lld",kruscal());return 0;
	}
	else{
		printf("0");
	}
	return 0;
} 
