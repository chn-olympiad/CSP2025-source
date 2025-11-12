#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e4+17,maxm=1e6+7,maxs=1<<10;
const ll inf=1e16;
ll ans=inf,sum;
int n,m,k;
int lg[maxs];
int f[maxs][maxn],c[maxs],v[maxn];
struct node{
	int l,r,w;
	bool operator <(const node &x) const{
		return w<x.w;
	}
}e[maxm],a[11][maxn],g[maxs][maxn];

int find(int s,int x){
	if(f[s][x]==x) return x;
	return f[s][x]=find(s,f[s][x]);
} 

inline bool merge(int s,int x,int y){
	int fx=find(s,x),fy=find(s,y);
	if(fx!=fy){
		f[s][fx]=fy;
		return 1;
	}
	return 0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[0][i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].l>>e[i].r>>e[i].w;
	sort(e+1,e+1+m);
	for(int i=0;i<k;i++) lg[1<<i]=i;
	for(int i=0;i<k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			a[i][j].l=n+i+1;
			a[i][j].r=j;
			cin>>a[i][j].w;
		}
		sort(a[i]+1,a[i]+1+n);
	}
	for(int i=1;i<=m;i++){
		if(merge(0,e[i].l,e[i].r)){
			g[0][++c[0]]=e[i];
			sum=sum+e[i].w;
			if(c[0]==n-1) break;
		}
	}
	ans=sum;
	for(int s=1;s<1<<k;s++){
		int t=(s^(s&-s)),pos=lg[s&-s];
		int tot=n+__builtin_popcount(s),len=0;
		for(int i=1,j=1;i<=n;i++){
			while(j<=c[t]&&g[t][j].w<a[pos][i].w){
				e[++len]=g[t][j];
				j++;
			}
			e[++len]=a[pos][i];
		}
		for(int i=1;i<=n+k;i++) f[s][i]=i;
		sum=0;
		for(int i=0;i<k;i++) if(s>>i&1) sum=sum+v[i];
		for(int i=1;i<=len;i++){
			if(merge(s,e[i].l,e[i].r)){
				g[s][++c[s]]=e[i];
				sum=sum+e[i].w;
				if(c[s]==tot-1) break;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
} 
