#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
struct edge{
	int x,y,w;
}e[M],E[M],t[M];
const edge INF=(edge){1,1,2000000000};
int n,m,k,s,len,c[K],fa[N],siz[N];
pair<int,int> a[K][N];
long long sum,ans=1e17;
bool vis[K];
int find(int x){return (x==fa[x])?x:fa[x]=find(fa[x]);}
void merge(int x,int y,int w){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		if(siz[fx]>siz[fy]){
			fa[fy]=fx;
			siz[fx]+=siz[fy];
		}else{
			fa[fx]=fy;
			siz[fy]+=siz[fx];
		}
		s++;sum+=w;
	}
}
bool cmp(edge a,edge b){return a.w<b.w;}
long long calc(){
	m=len;sum=0;
	int l=0;s=0;
	for(int i=1;i<=m;i++)E[i]=e[i];
	for(int i=1;i<=k;i++){
		if(vis[i]){
			sum+=c[i];l++;int L=0;
			for(int I=1,J=1;I<=m||J<=n;){
				edge x,y;
				if(I<=m)x=E[I];
				else x=INF;
				if(J<=n)y=(edge){a[i][J].second,n+l,a[i][J].first};
				else y=INF;
				if(x.w<=y.w)t[++L]=x,I++;
				else t[++L]=y,J++;
			}
			for(int i=1;i<=m+n;i++)E[i]=t[i];
			m+=n;
		}
	}
	for(int i=1;i<=n+l;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		merge(E[i].x,E[i].y,E[i].w);
		if(sum>=ans)return 1e17;
		if(s==n+l-1)break;
	}
	return sum;
}
void dfs(int x){
	if(x>k){
		ans=min(ans,calc());
		return ;
	}
	dfs(x+1);
	vis[x]=true;
	dfs(x+1);
	vis[x]=false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy){
			fa[fy]=fx;
			s++;e[++len]=e[i];
		}
		if(s==n-1)break;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j].first,a[i][j].second=j;
		sort(a[i]+1,a[i]+n+1);
	}
	dfs(1);
	cout<<ans;
	return 0;
}
