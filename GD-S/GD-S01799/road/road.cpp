/*
sto dl 保佑我这题不被卡常 orz orz orz 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define N 1000010
#define M 10035
struct edge{int u,v;ll w;}a[N],b[100010];// 边
bool cmp(edge n1,edge n2){return n1.w < n2.w;}
int n,m,k,lb,la;bool used[N];
ll ans,c[15][M],cost[15];
int dad[N],sze[N];// 按至和并 dsu
int find(int x){
	if(dad[x] == x)return x;
	dad[x] = find(dad[x]);return dad[x];
}
bool merge(int x,int y){
	x = find(x),y = find(y);
	if(x == y)return 0;
	if(sze[x] < sze[y])swap(x,y);
	dad[y] = x,sze[x] += sze[y];return 1;
}
void solve(int state){
	lb = 0;int all = n;ll res = 0;
	for(int i = 1;i <= n;++i)dad[i] = i,sze[i] = 1;
	for(int i = 1;i <= k;++i){
		if(state >> (i-1) & 1){++all;dad[n+i] = n+i,sze[n+i] = 1;res += cost[i];
			for(int j = 1;j <= n;++j){++lb;b[lb].u = n+i,b[lb].v = j,b[lb].w = c[i][j];}
		}
	}
	sort(b+1,b+lb+1,cmp);
	edge *now;int pa = 1,pb = 1;
	while(sze[find(1)] != all){
		if(pb > lb || a[pa].w < b[pb].w){now = &a[pa];++pa;}
		else{now = &b[pb];++pb;}int u = now->u,v = now->v;ll w = now->w;
		if(!merge(u,v))continue;res += w;
	}
	ans = min(ans,res);
}

int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;++i){int u,v;ll w;cin >> u >> v >> w;a[i].u = u,a[i].v = v,a[i].w = w;}sort(a+1,a+m+1,cmp);
	for(int i = 1;i <= k;++i){cin >> cost[i];
		for(int j = 1;j <= n;++j)cin >> c[i][j];
	}
	// 先做一遍 krusk
	for(int i = 1;i <= n;++i)dad[i] = i,sze[i] = 1;
	ans = 0;
	for(int i = 1;i <= m;++i){int u = a[i].u,v = a[i].v;ll w = a[i].w;
		if(!merge(u,v))continue;a[++la] = a[i],ans += w;
	}
	for(int s = 1;s < (1<<k);++s)solve(s);
	cout << ans;
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
