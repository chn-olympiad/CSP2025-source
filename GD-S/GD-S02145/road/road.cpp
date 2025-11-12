# include <bits/stdc++.h>
# define int long long
using namespace std;

const int N = 1e6 + 5;
int n,m,k,ans = 1e18+7;
struct edge {
	int u,v,wei;
};
edge g[N],gr[N*2];
int c[15],a[15][10005];
int par[10025];

bool cmp (edge a,edge b) {
	return a.wei < b.wei;
}

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

int cntku(int n,int m) {
	int cnt = 0;
	for (int i = 1;i <= n;i ++) par[i] = i;
	sort(gr+1,gr+1+m,cmp);
	for (int i = 1;i <= m;i ++) {
		int u = gr[i].u,v = gr[i].v,w = gr[i].wei;
		u = find(u),v = find(v);
		if (u == v) continue;
		cnt += w;
		par[u] = v;
	}
	return cnt;
}

/*void dfs(int st,int nn,int mm,int cnt) {
	if (st != 0) ans = max(cntku(nn,mm)+cnt,ans);
	for (int i = st+1;i <= k;i ++) {
		dfs(i,n+1,m+)
	}
}*/

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i ++) {
		cin >> g[i].u >> g[i].v >> g[i].wei;
	}
	for (int i = 1;i <= k;i ++) {
		cin >> c[i];
		for (int j = 1;j <= n;j ++) {
			cin >> a[i][j];
		}
	}
	int endnum = pow(2,k)-1;
	for (int i = 0;i <= endnum;i ++) {
		//cout << i << endl;
		for (int tt = 1;tt <= m;tt ++) gr[tt] = g[tt];
		int idxn=n,idxm = m,el = 0;
		for (int j = 1;j <= k;j ++) {
			if (i & (1<<(j-1))) {
				idxn ++;
				el += c[j];
				for (int l = 1;l <= n;l ++) {
					idxm ++;
					gr[idxm].u = idxn,gr[idxm].v = l,gr[idxm].wei=a[j][l];
				}
			}
		}
		//cout << i << endl;
		ans = min(ans,cntku(idxn,idxm)+el);
		//cout << i << " " << ans << endl;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
