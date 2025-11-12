#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+1e3,M=2*1e6,inf=1e16;
int n,m,q;
struct edge{
	ll f,t,v;
};
edge e[M];
ll c[N];
int f[N];

void init(){
	for(int i=0;i<N;i++) f[i]=i;
}

int ff(int x){
	if(f[x]==x) return x;
	else return f[x]=ff(f[x]);
}

void hb(int x,int y){
	int xx=ff(x),yy=ff(y);
	f[xx]=yy;
}

bool operator<(edge a,edge b){
	return a.v<b.v;
}

inline bool chk(int z,int x){
	if(x<=n) return 1;
	return z&(1<<(x-n-1));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>e[i].f>>e[i].t>>e[i].v;
	}
	for(int i=1;i<=q;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			ll tmp;
			cin>>tmp;
			e[++m]={n+i,j,tmp};
		}
	}
	sort(e+1,e+1+m);
	ll ans=inf;
	for(int z=0;z<(1<<q)-1;z++){
		init();
		int zs=0;
		ll sum=0;
		for(int i=1;i<=q;i++){
			if(chk(z,i+n)){
				sum+=c[i];
				++zs;
			}
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(chk(z,e[i].f) && chk(z,e[i].t)){
				int aa=ff(e[i].f),bb=ff(e[i].t);
				if(aa!=bb){
					hb(aa,bb);
					sum+=e[i].v;
					++cnt;
				}
			}
			if(sum>=ans) break;
			if(cnt==n+zs-1) break;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
