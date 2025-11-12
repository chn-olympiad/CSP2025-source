#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
const int N=1e8+5,M=1e4+5,K=1e6+5;
long long b[M];
int f[M];
long long c[M][M],ans=0;
struct baga{
	int u,v;
	ll w;
}a[K];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int h;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=c[j][i]=1e18;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		c[u][v]=min(c[u][v],w);
	}
	for(int i=1;i<=k;i++){
		int J;
		cin>>J;
		for(int j=1;j<=n;j++)cin>>b[j];
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				c[u][v]=min(c[u][v],J+b[u]+b[v]);
			}
		}
	}
	int cnt=0;
	for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++)a[++cnt]={u,v,c[u][v]};
	sort(a+1,a+cnt+1,[](baga x,baga y){return x.w<y.w;});
	for(int i=1;i<=cnt;i++){
//		cout<<a[i].w<<" ";
		int x=a[i].u,y=a[i].v;
		int X=find(x),Y=find(y);
		if(X!=Y){
//			cout<<x<<" "<<y<<" "<<a[i].w<<"\n";
			h++;
			f[X]=Y;
			ans+=a[i].w;
			if(h==n-1)break;
//			cout<<ans<<"\n";
		}
	}
	cout<<ans;
//	cout<<" "<<h;
	return 0;
}
