#include<iostream>
#include<algorithm>
using namespace std;
#define llong long long
const int N = 10001,M = 1000001;

llong mi,sum,ans;
int n,m,k,dis,f[N];
struct Edge{int u,v,w;}e[M];
bool cmp(Edge a,Edge b){return a.w < b.w;}

int find(int x){return f[x] = (x == f[x] ? x : find(f[x]));}
void un(int x,int y){f[find(y)] = find(x);return;}

llong krus(){
	sort(e+1,e+m+1,cmp);
	for(int i = 1,cnt = 1;cnt < n;++i){
		int u = e[i].u,v = e[i].v;
		if(find(u) == find(v)) continue;
		else un(u,v),++cnt,ans += e[i].w;
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;++i) f[i] = i;
	for(int i = 1;i <= m;++i)
		cin >> e[i].u >> e[i].v >> e[i].w;
	mi = krus();
	for(int i = 1;i <= k;++i){
		cin >> sum;
		for(int j = 1;j <= n;++j)
			cin >> dis,sum += dis;
		mi = min(mi,sum);
	}
	cout << mi;
	return 0;
}
