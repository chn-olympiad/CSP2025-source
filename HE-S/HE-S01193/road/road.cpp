#include<bits/stdc++.h>
#define int long long
#define mk(x,y) make_pair(x,y)
using namespace std;
int n,m,k;
int fa[200005];
int du[200005];
int f[100],co;
struct no{
	int u,v;int w;
}a[2000005];
bool cmp(no x,no y){
	return x.w< y.w;
}
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx != fy){
		fa[fx] = fy;
	}
}
int dis[100];
priority_queue <pair<int,int> > q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		q.push(mk(-a[i].w,i));
	}
	int h = n;
	int d = m;
	for(int i = 1;i <= k;i ++){
		cin >> f[i];
		h ++;
		for(int j = 1;j <= n;j ++){
			cin >> a[++ d].w;
			a[d].u = h,a[d].v = j;
			q.push(mk(-a[d].w,d));
		}
	}
	for(int i = 1;i <= h;i ++){
		fa[i] = i;
	}
	int cnt = n;
	long long ans = 0;
	if(k == 0){
		sort(a + 1,a + 1 + m,cmp);
		for(int i = 1;i <= m;i ++){
			if(find(a[i].u) == find(a[i].v))continue;
			merge(a[i].u,a[i].v);
			cnt --;
			ans += a[i].w;
			if(cnt == 1){
				cout << ans;
				return 0;
			}
		}
	}
	else{
		int sum = h;
		for(int i = 1;i <= d;i ++){
			pair <int,int> p = q.top();
			q.pop();
			int u = a[p.second].u,v = a[p.second].v;
			if(find(u) == find(v))continue;
			if(u > n){
				dis[u - n] += a[p.second].w;
			}
			ans += a[p.second].w;
			sum --; 
			du[u] ++,du[v] ++;
			merge(u,v);
			if(sum == 1)break;
		}
		for(int i = n + 1;i <= h;i ++){
			if(du[i] <= 1)ans -= dis[i - n];
			else{
				ans += f[i - n];
			}
		}
		cout << ans;
	}
	return 0;
}
