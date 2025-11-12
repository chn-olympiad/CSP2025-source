#include<bits/stdc++.h>
using namespace std;
int n,m,k,top,tot,ans;
bool vis[10100];
struct es {
	int pos,to,w,ad;
} e[1000100];
bool cmp(es x,es y) {
	return x.w<y.w;
}
void add(int x,int y,int co) {
	e[++top].pos=x;
	e[top].to=y;
	e[top].w=co;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1; i<=k; i++) {
		int C,c;
		scanf("%d",&C);
		for(int j=1; j<=n; j++) {
			scanf("%d",&c);
			//add(j,n+i,2*c+C);
			//add(n+i,j,2*c+C);
		}
	}
	sort(e+1,e+top+1,cmp);
	for(int i=1; i<=top; i++) {
		int x=e[i].pos,y=e[i].to;
		if(x<=n&&y<=n) {
			if(vis[x]&&vis[y])continue;
			if(!vis[x])vis[x]=1,tot++;
			if(!vis[y])vis[y]=1,tot++;
			ans+=e[i].w;
		}//else {
		//	if(y>n) {
		//		&&!vis[y]vis[y]=1;
		//		ans-=val[y];
	//		}
	//	}
		if(tot==n)break;
	}
	printf("%d",ans);
	return 0;
}
