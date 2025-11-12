#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+200;
int n,m,k;
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void set_(int x,int y){
	fa[find(x)]=find(y);
	return;
}
int c[15],a[15][N];
struct node{
	int u,v,w;
}e[M],ue[M],use[M];
long long ans=LLONG_MAX;
int mark[15];
bool cmp(node a,node b){
	return a.w<b.w;
}
int d;
void dfs(int step,long long cost){
	if(step==k+1){
		int cnt=d;
		for(int i=1;i<=d;i++){
			use[i]=ue[i];
		}
		for(int i=1;i<=k;i++){
			if(mark[i]){
				for(int j=1;j<=n;j++){
					use[++cnt].u=i+n;
					use[cnt].v=j;
					use[cnt].w=a[i][j];
				}
			}
		}
		sort(use+1,use+cnt+1,cmp);
		for(int i=1;i<=n+12;i++){
			fa[i]=i;
		}
		for(int i=1;i<=cnt;i++){
			if(find(use[i].u)!=find(use[i].v)){
				set_(use[i].u,use[i].v);
				cost+=use[i].w;
				if(cost>=ans){
					return;
				}
			}
		}
		ans=min(cost,ans);
		return;
	}
	mark[step]=1;
	dfs(step+1,cost+c[step]);
	mark[step]=0;
	dfs(step+1,cost);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w; 
	}
	for(int i=1;i<=k;i++){
		bool flag=0;
		cin>>c[i];
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)flag=1;
		}
		if(!flag){
			cout<<0<<"\n";
			return 0;
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	long long now=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			set_(e[i].u,e[i].v);
			now+=e[i].w;
			ue[++d]=e[i];
		}
	}
	ans=now;
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}
