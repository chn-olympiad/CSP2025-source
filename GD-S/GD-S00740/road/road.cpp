# include<bits/stdc++.h>
# define int long long
using namespace std;

const int N = 1e4+5,M = 1e6+5,inf = 1e18;
int n,m,k,f[N],cnt,c[N],ans,vis[N];
struct node {
	int x,y,z;
}arr[M],b[M];
int cmp(node a,node b) {
	return a.z < b.z;
}
void init() {
	for (int i = 1;i <= n+k;i++) f[i] = i;
}
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]); 
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1,x,y,z;i <= m;i++) {
		cin >> x >> y >> z;
		arr[i] = {x,y,z};
	}
	sort(arr+1,arr+m+1,cmp);
	init();
	for (int i = 1;i <= m;i++) {
		int fx = find(arr[i].x),fy = find(arr[i].y);
		if (fx != fy) b[++cnt] = arr[i],f[fx] = fy;
		if (cnt == n-1) break;
	}
	for (int i = 1;i <= k;i++) {
		cin >> c[i];
		for (int j = 1,x;j <= n;j++) {
			cin >> x;
			b[++cnt] = {n+i,j,x};
		}
	}
	sort(b+1,b+cnt+1,cmp);
	ans = inf;
	for (int i = 0;i < (1<<k);i++) {
		int sum = 0,idx = 0,cc = 0;
		for (int j = 1;j <= k;j++) vis[j] = 0;
		for (int j = 1;j <= k;j++) {
			if (i&(1<<j-1)) sum += c[j],vis[j] = 1;
		}
		init();
		for (int j = 1;j <= cnt;j++) {
			if (b[j].x>n && !vis[b[j].x-n]) continue;
			int fx = find(b[j].x),fy = find(b[j].y);
			if (fx != fy) f[fx] = fy,cc++,sum += b[j].z;
		}
		ans = min(ans,sum);
	}
	cout << ans << '\n';
	//cout << clock()*1000.0/CLOCKS_PER_SEC << "ms" << '\n';
	
	return 0;
}
