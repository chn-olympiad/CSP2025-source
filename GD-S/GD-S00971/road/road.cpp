#include<bits/stdc++.h>
#define int long long 
#define rep(i,a,b)	for(int i = (a);i<=(b);i++)
#define lep(i,a,b)	for(int i = (a);i>=(b);i--)
using namespace std;

const int N = 1e5+10;
const int M = 1e6+10;
const int inf = 1e18;
int n,m,k,ans;
int c[20],a[20][N];
int f[N];
struct edge{
	int u,v,w;
}e[M];
struct node{
	int u,v,w;
	bool operator <(const node &_)	const{
		return w>_.w;
	}
};
priority_queue<node> q;
inline bool cmp(edge _,edge __){
	return _.w<__.w;
}

inline int find(int x){
	if(x != f[x])	f[x] = find(f[x]);
	return f[x];
}
inline int merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy){
		f[fy] = fx;
		return 1;
	}
	return 0;
}
inline int calc(int s){
	int res = 0;
	int d = __builtin_popcount(s);
	while(q.size())	q.pop();
	rep(i,1,k){
		if((s>>(i-1))&1){
			res+=c[i];
			rep(j,1,n)	q.push(node{i+n,j,a[i][j]});
		}
	}
	rep(i,1,n+k)	f[i] = i;
	int cnt = n+d;
	rep(i,1,m){
		if(q.size()){
			int w = q.top().w;
			if(w<=e[i].w){
				int u = q.top().u,v = q.top().v;	q.pop();
				if(merge(u,v)){
					cnt--;
					res+=w;
				}
				if(cnt == 1)	break;
				i--;
				continue;
			}
		}
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if(merge(u,v)){
			cnt--;
			res+=w;
		}
		if(cnt == 1)	break;
	}
	return res;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin>>n>>m>>k;
	rep(i,1,m)	cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n)	cin>>a[i][j];
	}	
	ans = inf;
	rep(i,0,(1ll<<k)-1)	ans = min(ans,calc(i));
	cout<<ans;
	return 0;
}
