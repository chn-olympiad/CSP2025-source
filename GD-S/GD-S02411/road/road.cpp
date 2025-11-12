#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
const int M=1e6+5;
const ll INF=1e14;
int n,m,k,c[15],a[15][N],fat[N+10];
int cnt[15];
struct EDGE{
	int u,v,w;
}e[M+N*10];
bool cmp(EDGE px,EDGE py){
	return px.w<py.w;
}
int find(int pos){
	if(fat[pos]==pos) return pos;
	return fat[pos]=find(fat[pos]);
}
ll ans=INF;
bool vis[15];
ll tot[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			e[++m]=EDGE{i+n,j,a[i][j]};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int S=0;S<(1<<k);S++)
	{
		for(int i=1;i<=n+k;i++)
			fat[i]=i;
		bool pd1=false;
		ll res=0;
		for(int i=1;i<=k;i++)
		{
			cnt[i]=0;
			if((S>>(i-1))&1){
				if(vis[i]){
					pd1=true;
					break;
				}
				res+=c[i];
			}
		}
		if(pd1) continue;
		for(int i=1;i<=m;i++)
		{
			int x=e[i].u,y=e[i].v;
			bool pd2=false;
			if(x>n){
				int nx=x-n;
				if(((S>>(nx-1))&1)==0) pd2=true;
			}
			if(y>n){
				int ny=y-n;
				if(((S>>(ny-1))&1)==0) pd2=true;
			}
			if(pd2) continue;
			x=find(x),y=find(y);
			if(x!=y){
				res+=e[i].w;
				fat[x]=y;
				if(e[i].u>n) cnt[e[i].u-n]++;
				if(e[i].v>n) cnt[e[i].v-n]++;
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(((S>>(i-1))&1)==0) continue;
			if(cnt[i]<2) vis[i]=true;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
