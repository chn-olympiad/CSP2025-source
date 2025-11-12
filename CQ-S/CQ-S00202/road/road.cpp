#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=10005,M=1000005,mod=998244353;
const ll inf=0x3f3f3f3f;
#define pb push_back

int n,m,k;

struct node{
	int u,v,w;
	bool operator<(const node&res)const{
		return w<res.w;
	}
}e[N+M],E[M],b[M];
int fa[N+M];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int c[N],a[12][N];
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr); 
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		E[i]=e[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++m]={n+i,j,a[i][j]};
		}
	}
	n+=k;
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int x=getfa(e[i].u),y=getfa(e[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=e[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
