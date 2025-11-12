#include<bits/stdc++.h>

using namespace std;
const int N = 1e7;
struct node{
	long long v,u,w;
	bool operator <(const node &x){
	    return x.w < x.w;
	}
};
queue<node> s;

long long n,m,k,u,v,w,c[N],a,p[N],ans;
inline long long OP(long long x){
	return p[x] == x ? x : OP(p[x]);
}
bool f[N];
inline void QWQ(){
	while(!s.empty()){
		node k = s.front();
		s.pop();
		
		long long u = k.u ,v = k.v ,w = k.w ;
		if(OP(u) != OP(v)){
			p[OP(u)] = v;
			ans += w;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		cin >> u >> v >> w;
		s.push({u,v,w});
		
	}
	long long g = n;
	for(int i = 1;i <= k;i ++){
		cin >> c[++ g];
		for(int j = 1;j <= n;j ++){
			cin >> a;
			s.push({n,j,a + c[g]});
		}
	}
	for(int i = 1;i <= n;i ++){
		p[i] = i;
	}
	QWQ();
	cout << ans;
	return 0;
}
