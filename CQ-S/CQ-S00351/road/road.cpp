#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,x,y) for(register int i=x;i<=(int)y;++i)
#define rep1(i,x,y) for(register int i=x;i>=(int)y;--i)
#define pb push_back
#define fire signed
inline void in(int &x) {
	x=false;
	char c=getchar();
	while(c>'9'||c<'0') {
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+c-'0';
		c=getchar();
	}
}
void print(ll x) {
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
int T=1;
int n,m,k;
const int N=2e4+10,M=1e6+10;
int fa[N];
int a[15][N];
struct node{
	int x,y,z;
	inline friend bool operator<(const node&a,const node&b) {
		return a.z<b.z;
	}
}s[M],s1[N];
inline int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int idx;
int arr[N*10],tot;
vector<pair<int,int>>v1[N*10];
inline void solve() {
	in(n),in(m),in(k);
	rep(i,1,m) {
		int x,y,z;
		in(x),in(y),in(z);
		s[i]={x,y,z};
	}
	rep(i,1,k) rep(j,0,n) in(a[i][j]);
	rep(i,1,n) fa[i]=i;
	sort(s+1,s+1+m);
	ll res=0;
	rep(i,1,m){
		int tx=find(s[i].x),ty=find(s[i].y);
		if(tx==ty) continue;
		fa[tx]=ty;
		res+=s[i].z;
		s1[++idx]={s[i].x,s[i].y,s[i].z};
		arr[++tot]=s[i].z;
	}
	rep(i,1,k) rep(j,0,n) arr[++tot]=a[i][j];
	sort(arr+1,arr+1+tot);
	int mm=unique(arr+1,arr+1+tot)-arr-1;
	rep(i,1,k) rep(j,0,n) a[i][j]=lower_bound(arr+1,arr+1+mm,a[i][j])-arr;
	rep(i,1,idx) s1[i].z=lower_bound(arr+1,arr+1+mm,s1[i].z)-arr;
	rep(x,1,(1<<k)-1) {
		ll dis=0;
		rep(j,1,n+k) fa[j]=j;
		rep(i,1,mm) v1[i].clear();
		rep(j,1,idx) v1[s1[j].z].pb({s1[j].x,s1[j].y});
		rep(i,0,k-1) {
			if((x>>i)&1) {
				dis+=arr[a[i+1][0]];
				rep(y,1,n) {
					v1[a[i+1][y]].pb({i+n+1,y});
				}
			}
		}
		rep(now,1,mm) {
			for(auto to:v1[now]) {
				int tx=find(to.first),ty=find(to.second);
				if(tx==ty) continue;
				fa[tx]=ty;
				dis+=arr[now];
			}
			if(dis>=res) break;
		}
		res=min(res,dis);
	}
	print(res);
}
fire main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	while(T--) {
		solve();
	}
	return false;
}
/*
±ð¿¨ÎÒ³£,qwq. 
*/
