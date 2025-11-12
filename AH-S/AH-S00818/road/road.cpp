#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1e6+5;
vector<pair<int,int> >a[N];
int c[15],d[15][N],fa[N],g[15];
int n,m,k;
struct node{
	long long u,v,w;
}e[M+M];
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(){
	for(int i=1;i<=m+k;i++)
		fa[i]=i;
}
int find(int x){
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	int sum=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		sum+=c[i];
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	}
	if(sum==0){
		long long cur=0;
		int gg=n,cnt=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++)
				e[++cnt]={j,n+i,d[i][j]};
			cur+=c[i];
			gg++;
		}
		sort(e+1,e+cnt+1,cmp);
		int awa=0;
		init();
		for(int i=1;i<=cnt;i++){
			if(awa==gg-1)
				break;
			int l=e[i].u,r=e[i].v,du=e[i].w;
			if(find(l)==find(r))
				continue;
			merge(l,r);
			awa++;
			cur+=du;
		}
		cout<<cur;
		return ;
	}
	long long ans=LONG_LONG_MAX;
	for(int mark=0;mark<(1<<k);mark++){
		int x=mark,cnt=0;
		for(int i=1;i<=k;i++)
			g[i]=0;
		while(x>0){
			g[++cnt]=x%2;
			x/=2;
		}
		cnt=m;
		long long cur=0;
		int gg=n;
		for(int i=1;i<=k;i++){
			if(g[i]==0)
				continue;
			for(int j=1;j<=n;j++)
				e[++cnt]={j,n+i,d[i][j]};
			cur+=c[i];
			gg++;
		}
		sort(e+1,e+cnt+1,cmp);
		int awa=0;
		init();
		for(int i=1;i<=cnt;i++){
			if(awa==gg-1)
				break;
			int l=e[i].u,r=e[i].v,du=e[i].w;
			if(find(l)==find(r))
				continue;
			merge(l,r);
			awa++;
			cur+=du;
		}
		ans=min(ans,cur);
		for(int i=m+1;i<=cnt;i++)
			e[i]={0,0,0};
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--)
		solve();
	return 0;
}
//啊啊啊，有蜜蜂，蜜蜂快走