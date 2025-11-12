#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5,T=5e3+5;
int m,n,k,c[N],cnt,tot,sum,x,y,z,ans,f[N],fa[N],lk[T][T],flag[N];
bool vis[T][T];
struct flower{
	int u,v,w,f;
	bool operator < (const flower &css)const{
		return w<css.w;
	}
}e[N*N/2+M];
inline int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(lk[x][y]<e[i].w&&vis[x][y]) continue;
		else{
			cnt++;
			e[cnt].u=x;e[cnt].v=y;e[cnt].w=z;
			lk[x][y]=z;
			vis[x][y]=1;
		}
	}
	if(!k){
		sort(e+1,e+1+cnt);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=cnt;i++){
			x=find(e[i].u),y=find(e[i].v);
			if(x==y) continue;
			fa[x]=y;
			ans+=e[i].w;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>f[j];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(lk[j][k]<f[k]+f[j]+c[i]&&vis[j][k]) continue;
				cnt++;
				e[cnt].u=j;e[cnt].v=k;
				e[cnt].w=f[k]+f[j]+c[i];
				e[cnt].f=i;
				lk[j][k]=e[cnt].w;
				vis[j][k]=1;
			}
		}
	}
	sort(e+1,e+1+cnt);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;
		ans+=e[i].w;
	}
	cout<<ans<<'\n';
	return 0;
}
