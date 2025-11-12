#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=2e6+5;
int n,m,k,f[N],c[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
struct edge{int x,y,z;}e[M],tmp[M];
inline bool cmp(edge x,edge y){return x.z<y.z;}
long long ans=1ll<<60;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=n;++i) f[i]=i;
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;++i){
		int x=find(e[i].x),y=find(e[i].y);
		if(x!=y){
			tmp[++cnt]=e[i];
			f[x]=y;
		}
	}
	for(int i=1;i<=cnt;++i) e[i]=tmp[i];
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			int w;cin>>w;
			e[++cnt]=(edge){n+i,j,w};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int z=0;z<(1<<k);++z){
		long long sum=0;
		for(int i=1;i<=k;++i) if((z>>(i-1))&1) sum+=c[i];
		for(int i=1;i<=n+k;++i) f[i]=i;
		for(int i=1;i<=cnt;++i){
			if(e[i].x>n&&!((z>>(e[i].x-n-1))&1)) continue;
			int x=find(e[i].x),y=find(e[i].y);
			if(x!=y) sum+=e[i].z,f[x]=y;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

