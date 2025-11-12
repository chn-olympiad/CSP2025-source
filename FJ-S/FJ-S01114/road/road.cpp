#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long N=1e5+5,M=1e6+1e5+5,inf=1e9+5;
ll n,m,k,f[N],t[N],tt[15][N],cnt,tot,ans1,ans2;
ll vis[N];
struct edge{
	ll u,v,w;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool Union(ll x,ll y){
	ll fx=find(x);
	ll fy=find(y);
	if(fx!=fy){
		f[fy]=fx;
		return true;
	}return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;tot=m;
	for(int i=1;i<=m;i++)
	cin>>e[i].u>>e[i].v>>e[i].w;
	stable_sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=1;i<=m;i++)
	if(Union(e[i].u,e[i].v)){
		t[++cnt]=i;
		ans1+=e[i].w;
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++){
		cin>>tt[i][0];
		ll s1=inf,s2=inf;
		for(int j=1;j<=n;j++){
			cin>>tt[i][j];
			if(tt[i][j]<s1){
				s2=s1;
				s1=tt[i][j];
			}else if(tt[i][j]<s2) s2=tt[i][j];
		}
		if(s1+s2+tt[i][0]>e[t[cnt]].w) continue;
		ans2+=tt[i][0];
		for(int j=1;j<=n;j++){
			e[++tot].u=j;
			e[tot].v=n+i;
			e[tot].w=tt[i][j];
		}
	}
	stable_sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n+k+1;i++)
	f[i]=i;
	cnt=0;
	for(int i=1;i<=tot;i++)
	if(Union(e[i].u,e[i].v)){
		ans2+=e[i].w;
		if(e[i].u<=n&&!vis[e[i].u]){
			vis[e[i].u]=true;
			cnt++;
		}
		if(e[i].v<=n&&!vis[e[i].v]){
			vis[e[i].v]=true;
			cnt++;
		}
		if(cnt==n) break;
	}
	cout<<min(ans1,ans2);
	return 0;
}
