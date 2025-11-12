#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c[15],a[15][10005],d[15],ans,x,y;
long long rd[10005][10005];
struct s{
	long long w,u,v;
	friend bool operator <(s p,s q){
		return p.w<q.w;
	}
}r[1100005];
long long nm,cr[10005],co,fa[10005];
inline void add(long long u,long long v,long long w){
	nm++;
	r[nm].v=v,r[nm].u=u,r[nm].w=w;
}
inline long long zx(long long x){
	if(!fa[x]) return x;
	return zx(fa[x]);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(long long i=1;i<=m;i++){
		cin >> u >> v >> w;
		if(u>v) swap(u,v);
		add(u,v,w);
	}
	for(long long i=1;i<=k;i++){
		cin >> c[i];
		for(long long j=1;j<=n;j++){
			cin >> a[i][j];
			if(a[i][j]==0) d[i]=j;
		}
		for(long long j=1;j<=n;j++){
			if(d[i]!=j){
				add(min(d[i],j),max(d[i],j),a[i][j]);
			}
		}
	}
	sort(r+1,r+1+nm);
	for(long long i=1;i<=nm;i++){
		x=r[i].u,y=r[i].v;
		if(!rd[x][y]){
			if(!cr[x] && !cr[y]){
				co++;
				cr[x]=cr[y]=co;
			}
			else if(cr[x] && !cr[y]){
				cr[y]=cr[x];
			}
			else if(!cr[x] && cr[y]){
				cr[x]=cr[y];
			}
			else{
				long long cx=zx(cr[x]),cy=zx(cr[y]);
				if(cx==cy) continue;
				fa[cx]=cy;
			}
			rd[x][y]=r[i].w;
			ans+=r[i].w;
		}
		else if(rd[x][y]>r[i].w){
			ans-=rd[x][y];
			rd[x][y]=r[i].w;
			ans+=r[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
0 0 3 2 4

*/
