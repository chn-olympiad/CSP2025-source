#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15,M=1e6+5;
int n,m,k,cnt,fa[N],siz[N],val[15];
ll ans=1e18;
struct edge{
	int x,y,v;
}e[M],a[15][N],t[15][M*2];
bool cmp(edge x,edge y){
	return x.v<y.v;
}
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
bool mer(int x,int y){
	int fx=getfa(x),fy=getfa(y);
	if(fx==fy)return 0;
	if(siz[fx]>siz[fy])swap(fx,fy);
	fa[fx]=fy;
	siz[fy]+=siz[fx];
	return 1;
}
void dfs(int x,ll s,int p){
	if(x>k){
		for(int i=1;i<=n+k;i++){
			siz[i]=1;
			fa[i]=i;
		}
		int c=0;
		ll sum=s;
		for(int i=1;i<=m;i++){
			if(mer(t[k][i].x,t[k][i].y)){
				sum+=t[k][i].v;
				if(sum>ans)return;
				c++;
				if(c==p-1)break;
			}
		}
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=m;i++)t[x][i]=t[x-1][i];
	dfs(x+1,s,p);
	int p1=1,p2=1,len=m;
	cnt=0;
	while(p1<=m&&p2<=n){
		if(t[x-1][p1].v<a[x][p2].v)t[x][++cnt]=t[x-1][p1++];
		else t[x][++cnt]=a[x][p2++];
	}
	while(p1<=m)t[x][++cnt]=t[x-1][p1++];
	while(p2<=n)t[x][++cnt]=a[x][p2++];
	m=cnt;
	dfs(x+1,s+val[x],p+1);
	m=len;
}
int read(){
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		e[i].x=read();
		e[i].y=read();
		e[i].v=read();
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%d",&val[i]);
		for(int j=1;j<=n;j++){
			a[i][j]={n+i,j};
			a[i][j].v=read();
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	for(int i=1;i<=n;i++){
		siz[i]=1;
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)t[0][i]=e[i];
	for(int i=1;i<=m;i++){
		if(mer(e[i].x,e[i].y))t[0][++cnt]=e[i];
	}
	m=cnt;
	dfs(1,0,n);
	printf("%lld",ans);
	return 0;
}