#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
struct E{
	int u,v;
	long long w;
	bool operator< (const E &__e) const{
		return w > __e.w;
	}
} p[N];
int f[N],co[20][N],n,m,k;
int FindF(int x){
	if(f[x] == x){
		return x;
	}
	return f[x] = FindF(f[x]);
}
long long Func(int x,long long PreMin){
	priority_queue<E> qp;
	int rs = n;
	long long res = 0;
	for(int i=1;i<=m;i++){
		qp.push(p[i]);
	}
	for(int i=1;i<=10;i++){
		if((x&(1<<(i-1))) == 1){
			rs += 1;
			res += co[i][0];
			for(int x=1;x<=n;x++){
				qp.push(E{n+i,x,co[i][x]});
			}
		}
	}
	if(res > PreMin){
		return PreMin;
	}
//	cout << res << '\n';
	for(int i=1;i<=rs;i++){
		f[i] = i;
	}
	bitset<N> cnt;
	while((!qp.empty()) && cnt.count() < n){
//		printf("%d %d %d\n",qp.size(),qp.top().u,qp.top().v);
		if(FindF(qp.top().u) == FindF(qp.top().v)){
			qp.pop();
			continue;
		}
		if(qp.top().u <= n){
			cnt[qp.top().u] = 1;
		}
		if(qp.top().v <= n){
			cnt[qp.top().v] = 1;
		}
		res += qp.top().w;
		if(res > PreMin){
			return PreMin;
		}
//		printf("connect%d&%d sum(%d) cost%d\n",qp.top().u,qp.top().v,cnt.count(),qp.top().w);
		f[FindF(qp.top().u)] = FindF(qp.top().v);
		qp.pop();
	}
//	cout <<res << '\n';
	return res;
}
long long  solve(){
	long long res = LONG_LONG_MAX-1;
	for(int i=0;i<= ((1<<k)-1)/2;i++){
		res = min(res,Func(i,res));
		if(i != (1<<k)-1-i){
			res = min(res,Func((1<<k)-1-i,res));
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		p[i].u = u;
		p[i].v = v;
		p[i].w = w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&co[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&co[i][j]);
		}
	}
	printf("%lld\n",solve());
	return 0;
}
