#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+31,kMaxN=1e9+31;
int n,m,k,c[15];
int dis[N][N],sum,f[N],cnt;
bool vis[N];
struct edge{
	int u,v;
	ll w;
}a[N];
int find(int x){
	if(f[x]==x)	return f[x];
	return f[x]=find(f[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		cnt++;
		a[cnt].u=u;
		a[cnt].v=v;
		a[cnt].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ll d[N];
		for(int j=1;j<=n;j++){
			cin>>d[j];
		}
		for(int j=1;j<=n;j++){
			for(int l=i+1;l<=n;l++){
				cnt++;
				a[cnt].u=j;
				a[cnt].v=l;
				a[cnt].w=d[j]+d[l]+c[i];
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=n;i++)  f[i]=i;
	for(int i=1;i<=cnt;i++){
		int u=a[i].u;
		int v=a[i].v;
		ll w=a[i].w;
		if(i%10==0){
			bool tf=1;
			for(int i=2;i<=n;i++){
				if(find(f[i])!=find(f[i-1])){
					tf=0;
					break;
				}
			}
			if(tf)	break;
		}
		if(find(f[u])!=find(f[v])){
			u=find(u);
			v=find(v);
			f[v]=u;
			sum+=w;
		}
	}
	cout<<sum;
	return 0;
}
