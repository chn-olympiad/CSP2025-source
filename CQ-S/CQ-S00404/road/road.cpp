#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1e6+5,K=15;
int n,m,k;
struct edge{
	int x,y,w; 
	friend bool operator<(edge x,edge y){
		return x.w<y.w;
	}
}e[M],E[N];
int cnt;
int c[K];
struct node{
	int x,w;
	friend bool operator<(node x,node y){
		return x.w<y.w;
	}
}a[K][N];
int fa[N];
int findset(int x){
	return fa[x]=fa[x]==x?x:findset(fa[x]);
}
long long ans=1e18;
int mx;
vector<int> hav;
int pos[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j].w;
			a[i][j].x=j;
		}
		sort(a[i]+1,a[i]+n+1);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,x,y;i<=m;i++){
		x=findset(e[i].x),y=findset(e[i].y);
		if(x!=y){
			fa[x]=y;
			E[++cnt]=e[i];
			mx=e[i].w;
		}
	}
	for(int s=0;s<(1<<k);s++){
		long long res=0;
		int tot=0;
		hav.clear();
		for(int i=1;i<=k;i++){
			pos[i]=1;
			if((s>>i-1)&1){
				res+=c[i];
				hav.push_back(i);
			}
		}
		if(res>=ans){
			continue;
		}
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int i=1,x,y;i<=cnt;i++){
			for(int j=0;j<hav.size();j++){
				while(pos[hav[j]]<=n&&a[hav[j]][pos[hav[j]]].w<=E[i].w){
					x=findset(hav[j]+n),y=findset(a[hav[j]][pos[hav[j]]].x);
					if(x!=y){
						res+=a[hav[j]][pos[hav[j]]].w;
						fa[x]=y;
					}
					pos[hav[j]]++;
				}
			}
			x=findset(E[i].x),y=findset(E[i].y);
			if(x!=y){
				res+=E[i].w;
				fa[x]=y;
				if(res>=ans){
					break;
				}
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
