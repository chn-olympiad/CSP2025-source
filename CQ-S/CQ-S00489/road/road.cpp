#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nn{
	int u,v,w;
}a[5000001];
int c[11][10001],dist[1001][1001];
bool cmp(nn a,nn b){
	return a.w<b.w;
}
int p[10001];
int Find(int x){
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}
void Merge(int x,int y){
	x=Find(x),y=Find(y);
	p[y]=x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,K;
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	bool d=1;
	for(int i=1;i<=K;i++)
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j])d=0;
		}
	memset(dist,0x7f,sizeof dist);
	for(int x=1;x<=K;x++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dist[i][j]=min(dist[i][j],c[x][i]+c[x][j]+c[x][0]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			a[++m].u=i;
			a[m].v=j;
			a[m].w=dist[i][j];
		}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v;
		if(Find(u)!=Find(v)){
			Merge(u,v);
			ans+=a[i].w;
		}
	}
	cout<<ans;
}
