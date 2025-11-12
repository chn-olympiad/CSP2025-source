#include<bits/stdc++.h>
using namespace std;

#define ll long long
int read(){
	int s=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+(c&15);
		c=getchar();
	}
	return s;
}

const int N=1e4+100+5,M=1e6+5;

int n,m,k;
struct edge{
	int u,v,w;
}e[M],a[15][N];
vector<edge>ed[1025];
int nw,ct;
bool cmp(edge x,edge y){
	return x.w<y.w;
}

int c[N],f[N];
ll sum;

int find(int u){
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}
void merge(int u,int v,int w){
	if(find(u)==find(v))return;
	f[find(u)]=find(v);
	ed[nw].emplace_back(edge{u,v,w});
	sum+=w;
}

signed main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j].w=read();
			a[i][j].u=n+i,a[i][j].v=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	for(int i=1;i<=m;i++)
		merge(e[i].u,e[i].v,e[i].w);
	ll ans=sum;
	for(nw=1;nw<(1<<k);nw++){
		sum=0,ct=0;
		for(int i=1;i<=k;i++)
			if(nw&(1<<i-1))sum+=c[i];
		int cnt=__builtin_popcount(nw);
		for(int i=1;i<=n+k;i++)f[i]=i;
		int pre=(nw&(nw-1)),p=__lg(nw-pre)+1;
		int pos=1;
		for(auto ee:ed[pre]){
			while(pos<=n&&a[p][pos].w<ee.w)
				merge(a[p][pos].u,a[p][pos].v,a[p][pos].w),pos++;
			merge(ee.u,ee.v,ee.w);
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	
	return 0;
}
