#include<bits/stdc++.h>

using namespace std;

inline int read() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
long long n,m,k,fa[20005],Size[20005],cnt,c[15],ans=1e18,flag[15];
struct node{
	int x,y,w;
}p[1000005],B[11][10005],now[11][110005];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int find(int x) {
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
void merge(int fx,int fy) {
	if(Size[fx]>Size[fy]) swap(fx,fy);
	fa[fx]=fy,Size[fy]+=Size[fx];
}
long long check(int tot) {
	for(int i=1;i<=n+k;i++) fa[i]=i,Size[i]=1;
	long long sum=0;
	for(int i=1;i<=tot;i++) {
		int fx=find(now[k][i].x),fy=find(now[k][i].y);
		if(fx!=fy) sum+=now[k][i].w,merge(fx,fy);
	}
	return sum;
}
void dfs(int step,long long sum,int tot) {
	if(step==k+1) {
		ans=min(ans,check(tot)+sum);
		return;
	}
	for(int i=1;i<=tot;i++) now[step][i]=now[step-1][i];
	dfs(step+1,sum,tot);
	int t=1,T=0;
	for(int i=1;i<=tot;i++) {
		while(t<=n&&now[step-1][i].w>B[step][t].w) now[step][++T]=B[step][t],t++;
		now[step][++T]=now[step-1][i];
	}
	while(t<=n) now[step][++T]=B[step][t],t++;
	flag[step]=1,dfs(step+1,sum+c[step],tot+n),flag[step]=0;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) p[i].x=read(),p[i].y=read(),p[i].w=read();
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) B[i][j]={i+(int)n,j,read()};
		sort(B[i]+1,B[i]+n+1,cmp);
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i,Size[i]=1;
	for(int i=1;i<=m;i++) {
		int fx=find(p[i].x),fy=find(p[i].y);
		if(fx!=fy) now[0][++cnt]=p[i],fa[fx]=fy;
	}
	dfs(1,0,n-1);
	cout<<ans;
	return 0;
}
