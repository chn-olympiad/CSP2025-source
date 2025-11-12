#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k,c[N],a[15][N],cnt,h[N],g[10005][10005],fa[N];
int jim=0;
bool v[N];
struct bn{
	int l,r,w;
}edge[30000005];
bool cmp(bn a,bn b){
	return a.w<b.w;
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	jim=m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>edge[i].l>>edge[i].r>>edge[i].w;
		g[edge[i].l][edge[i].r]=g[edge[i].r][edge[i].l]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int ft=1;ft<n;ft++){
			for(int sd=ft+1;sd<=n;sd++){
				int now=g[ft][sd];
				if(!now){
					g[ft][sd]=g[sd][ft]=++jim;
					edge[jim].l=ft,edge[jim].r=sd,edge[jim].w=a[i][ft]+a[i][sd]+c[i];
				}
				else if(edge[now].w>a[i][ft]+a[i][sd]+c[i]){
					edge[now].w=a[i][ft]+a[i][sd]+c[i];
//					if(v[i]) edge[now].w-=c[i];
//					v[i]=1;
				}
			}
		}
	}
	sort(edge+1,edge+1+jim,cmp);
//	for(int i=1;i<=jim;i++) cout<<edge[i].l<<" "<<edge[i].r<<" "<<edge[i].w<<'\n';
	int num=0,ans=0;
	for(int i=1;i<=jim;i++){
		if(num==n-1) break;
		int x=edge[i].l,y=edge[i].r;
		if(get(x)==get(y)) continue;
		merge(x,y);
		ans+=edge[i].w;
		num++;
	}
	cout<<ans;
	return 0;
}

