#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+15;
const int N=1e4+15;
const int K=15;
int n,m,k,x,y,cnt,fa[N],tot[(1<<10)+5],cntt[(1<<10)+5];
ll ans,c[K],f[(1<<10)+5],sum[(1<<10)+5];
struct node{
	int u,v;
	ll w;
}a[M],b[K][N],e[(1<<10)+5][N],t[2*N];
bool cmp(node x,node y){
	return x.w<y.w;
}
void get_fa(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void Kruskal(int n,int s){
	get_fa();
	cnt=0ll;
	for(int i=1;cnt<n-1;i++){
		x=find(t[i].u),y=find(t[i].v);
		if(x==y)continue;
		f[s]+=t[i].w;
		fa[x]=y;
		cnt++;
		e[s][++tot[s]]=t[i];
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j].w;
			b[i][j].u=n+i;
			b[i][j].v=j;
		}
		sort(b[i]+1,b[i]+1+n,cmp);
	}
	get_fa();
	for(int i=1;i<=m&&cnt<n-1;i++){
		x=find(a[i].u),y=find(a[i].v);
		if(x==y)continue;
		f[0]+=a[i].w;
		fa[x]=y;
		cnt++;
		e[0][++tot[0]]=a[i];
	}
	ans=f[0];
	for(int i=1;i<=k;i++)
		for(int j=(1ll<<(i-1ll));j<=(1ll<<i)-1ll;j++){
			x=(j^(1ll<<(i-1ll)));
			sum[j]=sum[x]+c[i];
			cntt[j]=cntt[x]+1ll;
			int i1=1ll,j1=1ll,k1=0ll;
			//¹é²¢ e[x] ºÍ b[i]
			while(i1<=tot[x]&&j1<=n){
				while(e[x][i1].w<=b[i][j1].w&&i1<=tot[x])t[++k1]=e[x][i1++];
				while(b[i][j1].w<=e[x][i1].w&&j1<=n)t[++k1]=b[i][j1++];
			}
			while(i1<=tot[x])t[++k1]=e[x][i1++];
			while(j1<=n)t[++k1]=b[i][j1++];
//			cout<<j<<"\n";
//			for(int l=1;l<=k1;l++)cout<<t[l].u<<" "<<t[l].v<<" "<<t[l].w<<"\n";
//2^k*(2*n+2*n+log(2*n));
			Kruskal(n+cntt[j],j);
			f[j]+=sum[j];
			ans=min(ans,f[j]);
		}
	cout<<ans;
	return 0;
}
