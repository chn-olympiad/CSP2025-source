#include<bits/stdc++.h>
#define ll long long
#define psb push_back
using namespace std;
const int N=1e4+20,M=1e6+20;
int n,m,k,ed[11][N],fa[N],c[11];
struct edge{
	int x,y,z;
}e[M],E[M],e1[M];
void init(){
	for(int i=1;i<=n+10;i++)
		fa[i]=i;
}
inline int ga(int x){
	return x==fa[x]?x:fa[x]=ga(fa[x]);
}
bool cmp(edge x,edge y){
	return x.z<y.z;
}
void solve(){
	cin>>n>>m>>k;
	ll ans=0;
	init();
	int mx=0; 
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].z;
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		x=ga(x),y=ga(y);
		if(x!=y)
			ans+=e[i].z,e1[++cnt]=e[i],fa[x]=y,mx=max(mx,e[i].z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>ed[i][j];
	}
	for(int i=1;i<1<<k;i++){
		cnt=n-1;
		for(int j=1;j<n;j++)
			E[j]=e1[j];
		ll res=0;
		for(int j=1;j<=k;j++)
			if((1<<(j-1))&i){
				res+=c[j];
				for(int l=1;l<=n;l++)
					if(ed[j][l]<=mx)
						E[++cnt].x=n+j,E[cnt].y=l,E[cnt].z=ed[j][l];
			}
		init();
		sort(E+1,E+cnt+1,cmp);
		for(int j=1;j<=cnt;j++){
			int x=E[j].x,y=E[j].y,z=E[j].z;
			x=ga(x),y=ga(y);
			if(x!=y)
				res+=E[j].z,fa[x]=y;
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
} 
