#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5,K=15;
int n,m,k,c[K],a[K][N],mm;
bool vis[M];
int fa[N*2];
int find(int x){
	return (x==fa[x] ? x : fa[x]=find(fa[x]));
}
inline void join(int x,int y){
	fa[find(x)]=find(y);
	return;
}
struct node{
	int u,v,w,vis;
}e[M],ed[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	long long sum=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))continue;
		join(u,v);
		sum+=w;
		ed[++mm]=e[i];
		vis[i]=1;
	}
	if(k==0){
		cout<<sum;
		return 0;
	}
	long long res=sum;
	for(int s=0;s<(1<<k);s++){
		long long ans=0,nm=mm;
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				ans+=c[i];
				for(int j=1;j<=n;j++){
					nm++;
					ed[nm].u=i+n;
					ed[nm].v=j;
					ed[nm].w=a[i][j];
					ed[nm].vis=1;
				}
			}
		}
		sort(ed+1,ed+nm+1,cmp);
		for(int i=1;i<=n*2;i++)fa[i]=i;
		sum=0;
		for(int i=1;i<=nm;i++){
			int u=ed[i].u,v=ed[i].v,w=ed[i].w;
			if(find(u)==find(v))continue;
			join(u,v);
			sum+=w;
		}
		res=min(res,sum+ans);
		for(int i=1;i<=nm;i++){
			if(ed[i].vis==1)ed[i].w=2e9;
		}
		sort(ed+1,ed+nm+1,cmp);
	}
	cout<<res;
	return 0;
}
