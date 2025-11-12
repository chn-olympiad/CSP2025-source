#include <bits/stdc++.h>
#define up(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define dn(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define fst first
#define sed second
#define Max(x,y) (((x)>(y))?(x):(y))
#define Min(x,y) (((x)<(y))?(x):(y))
#define Abs(x) (((x)<0)?(-(x)):(x))
using namespace std;
using ll=long long;using ull=unsigned long long;using hint=__int128;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pil=pair<int,ll>;
using pli=pair<ll,int>;using vi=vector<int>;using vl=vector<ll>;
using vpi=vector<pii>;using vpl=vector<pll>;using vpli=vector<pli>;
using vpil=vector<pil>;using ui=unsigned int;using db=double;
using ldb=long double;
namespace my{
	const int N=(int)(1e4+25),M=(int)(1e6+25),P=(int)(998244353);
	const int inf=(int)(1e9);
	int n,m,k;
	struct edge{
		int x,y;ll w;int k;
	}e[M];
	int f[N];
	ll a[12][N],c[12];
	inline void init(){
		up(i,1,n+k+1)f[i]=i;
	}
	int find(int x){
		return f[x]==x?x:f[x]=find(f[x]);
	}
	vector<edge>choose;
	void SOLVE(){
		cin>>n>>m>>k;
		up(i,1,m)cin>>e[i].x>>e[i].y>>e[i].w,e[i].k=0;
		up(i,1,k){
			cin>>c[i];
			up(j,1,n)cin>>a[i][j];
		}
		sort(e+1,e+1+m,[&](edge x,edge y){
			return x.w<y.w;
		});
		int cnt=0;
		ll ans=0;
		init();
		up(i,1,m){
			int tx=find(e[i].x),ty=find(e[i].y);
			if(tx==ty)continue;
			f[ty]=tx;
			cnt++;
			ans+=e[i].w;
			choose.push_back(e[i]);
			if(cnt==n-1)break;
		}
		up(i,1,k)up(j,1,n)choose.push_back({i+n,j,a[i][j],i});
		sort(choose.begin(),choose.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		int t=(1<<k)-1;
		up(S,1,t){
			ll eans=0;
			int get=0;
			init();
			cnt=0;
			up(i,0,k-1)if((S>>i)&1)eans+=c[i+1],get++;
			for(edge v:choose){
				if(v.k!=0&&(!((S>>(v.k-1))&1)))continue;
				int tx=find(v.x),ty=find(v.y);
				if(tx==ty)continue;
				f[ty]=tx;
				cnt++;
				eans+=v.w;
				if(cnt==n+get-1)break;
			}
			if(cnt==n+get-1)ans=Min(ans,eans);
		}cout<<ans<<'\n';
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int _=1;while(_--)my::SOLVE();return 0;
}
/*
is O(2^k*kn) I think it can Ac this problem
*/
