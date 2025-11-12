#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, id=0, w[15][10050], cnt=0, f[10050], d[15], ans=0;
struct qwe{
	int x, y, z;
}a[1000050], b[200050], c[200050];
int fd(int x) {
	if(f[x]==x) return x;
	else return f[x]=fd(f[x]);
}
bool cmp(qwe x, qwe y) {
	return x.z<y.z;
}
int out(int sum) {
	int anss=sum;
	for(int i=1; i<=id; i++) {
		c[i].x=a[i].x;
		c[i].y=a[i].y;
		c[i].z=a[i].z;
	}
	sort(c+1, c+id+1, cmp);
	for(int i=1; i<=n+k; i++) f[i]=i;
	for(int i=1; i<=id; i++) {
		int fx=fd(c[i].x), fy=fd(c[i].y);
		if(fx!=fy) {
			f[fx]=fy;
			anss+=c[i].z;
		} 
	}
//	cout<<anss<<"\n";
	return anss;
}
void dfs(int now, int sum) {
	if(now==k+1) {
		ans=min(ans, out(sum));
		return ;
	}
	dfs(now+1, sum);
	int ID=id;
	for(int i=1; i<=n; i++) {
		a[++id].x=i;
		a[id].y=now+n;
		a[id].z=w[now][i];
	}
	dfs(now+1, sum+d[now]);
	id=ID;
	return ;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1, a+m+1, cmp);
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=1; i<=m; i++) {
		int fx=fd(a[i].x), fy=fd(a[i].y);
		if(fx!=fy) {
			f[fx]=fy;
			ans+=a[i].z;
			cnt++;
			a[cnt].x=a[i].x;
			a[cnt].y=a[i].y;
			a[cnt].z=a[i].z;
		}
	}
	for(int i=1; i<=k; i++) {
		cin>>d[i];
		for(int j=1; j<=n; j++) cin>>w[i][j];
	}
	id=cnt;
	dfs(1, 0);
	cout<<ans;
	return 0;
} 
