#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 15,M = 1e6 + 5,K = 15;
const long long inf = 1e18;
struct node{
	int start,end;
	long long dis;
	bool operator <(const node &x) const{ return dis > x.dis; }
	bool operator >(const node &x) const{ return dis < x.dis; }
};
int n,m,k,u,v;
long long w,a[K][N],c[K],ans,sum;
vector <node> mp[N],ed[1 << K],edg;
int lg2(int x){
	int res = 0;
	while(x > 1) x >>= 1,++res;
	return res;
}

int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void init(int len){
	for(int i = 1; i <= len; i++) fa[i] = i;
}
priority_queue <node> q;
long long kru(int v,int S){
	init(n + k);
	sort(edg.begin(),edg.end(),greater<node>());
	long long res = 0;
	for(auto e : edg){
		if(find(e.end) == find(e.start)) continue;
		ed[S].push_back(e),res += e.dis,fa[find(e.end)] = find(e.start),--v;
		if(v == 1) break;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%lld",&u,&v,&w);
		mp[u].push_back({u,v,w});
	}
	for(int j = 1; j <= k; j++){
		scanf("%lld",&c[j]);
		for(int i = 1; i <= n; i++){
			scanf("%lld",&a[j][i]);
			mp[n + j].push_back({n + j,i,a[j][i]});
		}
	}
	for(int i = 1; i <= n; i++){
		for(auto j : mp[i]) edg.push_back(j);
	}
	ans = kru(n,0);
	for(int S = 1; S < (1 << k); S++){
		edg.resize(0);
		int S_ = S ^ (S & (-S));
		for(auto j : ed[S_]) edg.push_back(j);
		v = n,sum = 0;
		bool flag = true;
		for(int j = 0; j < k; j++){
			if(S & (1 << j)){
				++v,sum += c[j + 1];
				if(flag){
					flag = false;
					for(auto l : mp[n + j + 1]) edg.push_back(l);
				}
			}
			
		}
		sum += kru(v,S);
		ans = min(ans,sum);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
