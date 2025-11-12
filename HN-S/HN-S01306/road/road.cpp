#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10,K=15;

int n,m,k;

struct E{
	int x,y;
	ll w;
}e[M];

bool Cmp(E x,E y){
	return x.w<y.w;
}

ll c[K];
ll a[K][N];

int fa[N];

int Get(int x){
	if(x==fa[x]) return x;
	return fa[x]=Get(fa[x]);
}

void Solve1(){
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(e+1,e+m+1,Cmp);
	int cnt=0; 
	ll ans=0;
	for(int i=1;i<=m;++i){
		int x=e[i].x,y=e[i].y,w=e[i].w;
		if(Get(x)!=Get(y)){
			++cnt; 
			ans+=w;
			fa[x]=Get(fa[y]);
			if(cnt==n-1) break;
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>e[i].x>>e[i].y>>e[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>a[i][j];
	}
	
	if(k==0) Solve1();
	
	return 0;
}

