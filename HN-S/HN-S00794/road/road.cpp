#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+5,M=2e6+5;
int n,m,k,c[N],tot;
struct edge{
	int x,y,w;
	bool fl,ap;
	edge(){x=y=w=fl=ap=0;}
	edge(int _x,int _y,int _w,bool _fl,bool _ap):x(_x),y(_y),w(_w),fl(_fl),ap(_ap){}
	void read(){cin>>x>>y>>w;}
	bool operator<(const edge&e)const{return w<e.w;}
}v[M],e[M];
bool b[N+15];
int f[N+15];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void kruskal(){
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		if(find(v[i].x)==find(v[i].y))continue;
		f[find(v[i].x)]=find(v[i].y);
		e[++tot]=v[i];
	}
}
ll calc(){
	ll cnt=0;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=tot;i++){
		int x=e[i].x,y=e[i].y;
		if(!b[x]||!b[y])continue;
		if(find(x)==find(y))continue;
		f[find(x)]=find(y);
		cnt+=e[i].w;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)v[i].read();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			e[++tot]=edge(i+n,j,w,1,0);
		}
	}
	sort(v+1,v+m+1);
	kruskal();
	for(int i=1;i<=n;i++)b[i]=1;
	sort(e+1,e+tot+1);
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		ll cnt=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1)b[j+n]=1,cnt+=c[j];
			else b[j+n]=0;
		}
		ans=min(ans,cnt+calc());
	}
	cout<<ans;
	return 0;
}

