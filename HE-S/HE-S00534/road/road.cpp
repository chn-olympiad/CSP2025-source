#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <typename T>
inline void read(T&x){
	int w = 0; x = 0;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') w = 1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		x = x*10+(ch^48);
		ch = getchar();
	}
	if(w) x = -x;
}
template <typename T,typename...Args>
inline void read(T&t,Args&...args){
	read(t); read(args...);
}
template <typename T>
inline T Max(T x,T y){ return (x > y ? x : y); }
template <typename T>
inline T Min(T x,T y){ return (x < y ? x : y); }
template <typename T>
inline T Abs(T x){ return (x < 0 ? -x : x); }
const int N = 1e4+10,M = 1e6+10,V = 15;
int n,m,K;
struct Ed{
	int u,v,w;
	inline int operator < (const Ed&G) const{
		return w < G.w; 
	}
}edge[M+10*N],d[V][N];
int c[V];
int fa[N+V];
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}
int f1 = 1;
namespace Sub1{
inline void solve(){;
	for(int i=1;i<=K;++i){
		for(int j=1;j<=n;++j){
			edge[++m] = d[i][j]; 
		}
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=n+K;++i) fa[i] = i;
	ll ans = 0;
	for(int i=1,cnt = 0;i<=m;++i){
		int x = edge[i].u;
		int y = edge[i].v;
		int w = edge[i].w;
		int tx = find(x);
		int ty = find(y);
		if(tx^ty){
			ans += w;
			fa[tx] = ty;
			++cnt;
			if(cnt==n+K-1) break;
		}
	}
	printf("%lld",ans);
}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	read(n,m,K);
	for(int i=1,u,v,w;i<=m;++i){
		read(u,v,w);
		edge[i] = {u,v,w};
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=K;++i){
		read(c[i]);
		if(c[i]) f1 = 0;
		for(int j=1,w;j<=n;++j){
			read(w);
			d[i][j] = {i+n,j,w};
		}
//		sort(d[i]+1,d[i]+1+n);
	}
	if(f1){
		Sub1 :: solve();
		return 0;
	}
	for(int i=1;i<=K;++i) sort(d[i]+1,d[i]+1+n);
	int S = (1<<K)-1;
	ll ans = LONG_LONG_MAX;
	for(int s=0;s<=S;++s){
		int flag = 0;
		for(int i=0;i<=n+K;++i) fa[i] = i;
		vector <Ed> vec;
		ll res =  0;
		for(int i=1;i<=K;++i){
			if((s>>(i-1))&1){
				res += c[i];
				if(res>=ans){
					flag = 1;
					break;
				}
//				cout << s << " " << i << endl;
				for(int j=1;j<=n;++j){
					vec.push_back(d[i][j]);
				}
			}
		}
		if(flag) continue;
//		cout << s << " " << res << endl;
		sort(vec.begin(),vec.end());
//		for(int i=0;i<vec.size();++i) cout << vec[i].u<< " " << vec[i].v << " " << vec[i].w << endl;

		for(int i=1,si = vec.size(),nowv = 0,cnt = 0;i<=m || nowv<si;){
			int x,y,w;
			if(i>m && nowv>=si) break;
			if(i>m){
				x = vec[nowv].u;
				y = vec[nowv].v;
				w = vec[nowv].w;
				++nowv;
			}
			else if(nowv>=si){
				x = edge[i].u;
				y = edge[i].v;
				w = edge[i].w;
				++i;
			}
			else if(i<=m && nowv<si){
				if(vec[nowv].w<edge[i].w){
					x = vec[nowv].u;
					y = vec[nowv].v;
					w = vec[nowv].w;
					++nowv;
				}
				else{
					x = edge[i].u;
					y = edge[i].v;
					w = edge[i].w;
					++i;
				}
			}
			int tx = find(x);
			int ty = find(y);
			if(tx^ty){
				res += (ll)w;
				fa[tx] = ty;
				++cnt;
				if(res>=ans){
					flag = 1;
					break; 
				}
				if(cnt==n+K-1) break;
			}
		}
		if(flag) continue;
		ans = Min(ans,res);
//		cout << s << " " << ans << endl;
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
