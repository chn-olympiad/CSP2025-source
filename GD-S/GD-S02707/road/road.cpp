#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define REP(i,x,y) for(int (i)=(x);(i)>=(y);(i)--)
#define fastIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
const int N=10023;
const int M=1000003;
const ll INF = 1e17;
int n,m,k,cnt,fa[N];
ll c[12],ans;
bool usd[12];
int FinD(int x){ if(fa[x]==x) return x;
	return fa[x]=FinD(fa[x]);
}
struct Edges{ int x,y; ll z;
	bool operator < (const Edges& B) const{ return z<B.z; }
}e[M],g[M],f[N];
void Krus(){ sort(e+1,e+m+1);
	rep(i,1,n) fa[i]=i;
	ll val=0; int fx,fy,fz=0;
	rep(i,1,m){ fx=FinD(e[i].x); fy=FinD(e[i].y); if(fx==fy) continue;
		f[++fz]=e[i]; fa[fx]=fy; val+=e[i].z; if(fz==n-1) break;
	} ans=val;
}
ll Solve(int num,ll Ad){ ll val=0;
	int fx,fy,fz=0,i=1,j=1;
	rep(i,1,n+k) fa[i]=i;
	while(fz<n+num-1){
		if(j<=cnt&&(i==n||f[i].z>g[j].z)){
			if(g[j].x>n) if(!usd[g[j].x-n]){ ++j; continue; }
			if(g[j].y>n) if(!usd[g[j].y-n]){ ++j; continue; }
			fx=FinD(g[j].x); fy=FinD(g[j].y);
			if(fx==fy){ ++j; continue; } ++fz;
			fa[fx]=fy; val+=g[j].z; if(fz==n+num-1) break; ++j;
		}
		else{ fx=FinD(f[i].x); fy=FinD(f[i].y); if(fx==fy){ ++i; continue; } ++fz;
			fa[fx]=fy; val+=f[i].z; if(fz==n+num-1) break; ++i;
		}
		if(val+Ad>ans) return INF;
	}
	return val+Ad;
} 
void dfs(int x,ll y,int z){
	if(x==k+1){ if(!z) return;
		ans=min(ans,Solve(z,y)); return;
	}
	usd[x]=0; dfs(x+1,y,z); usd[x]=1; dfs(x+1,y+c[x],z+1); usd[x]=0;
}
int main(){ freopen("road.in","r",stdin); freopen("road.out","w",stdout); fastIO; 
	cin>>n>>m>>k;
	rep(i,1,m) cin>>e[i].x>>e[i].y>>e[i].z; int Id,num;
	rep(i,1,k){ cin>>c[i];
		rep(j,1,n){ cin>>num; g[++cnt]=(Edges){i+n,j,num}; }
	} sort(g+1,g+cnt+1);
	if(n==1){ cout<<0; return 0; }
	Krus(); dfs(1,0,0);
	cout<<ans; return 0;
}
