#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e4+20,M=3e6+5;
int T,n,m,k,cnt,inw,c[N],a[11][N],fa[N];
ll ans;

struct edge{
	int u,v,w;
}e[M]; 

bool cmp(edge aaa,edge baa){
	return aaa.w<baa.w;
}

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void kru(){
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu==fv) continue;
		inw++;
		ans+=e[i].w;
		fa[fu]=fv;
		if(inw==n-1) return;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
			e[++cnt]={n+i,j,a[i][j]};
		} 
	}
	n+=k;
	kru();
	cout<<ans;
	return 0;
}
