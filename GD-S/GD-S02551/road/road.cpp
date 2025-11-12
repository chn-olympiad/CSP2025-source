#include <bits/stdc++.h>
using namespace std;

long long n, m, k, ans = 0x3f3f3f3f, cnt, cur;
struct Edge{
	long long u, v, w;
	bool operator<(const Edge &x)const{
		return w < x.w;
	}
} ;
Edge e[1000005], nw[10505], ed[130005];
long long c[15], a[10505][15];
struct mfm{
	long long p[10505], sz[10505];
	void pre(long long n){
		for(int i = 1;i <= n;i++)
			p[i] = i, sz[i] = 1;
		return ;
	}
	long long fnd(long long x){
		if(p[x] == x)
			return x;
		return p[x] = fnd(p[x]);
	}
	void mrg(long long x, long long y){
		x = fnd(x), y = fnd(y);
		if(x == y)
			return ;
		if(sz[x] < sz[y])
			sz[y] += sz[x], p[x] = y;
		else
			sz[x] += sz[y], p[y] = x;
		return ;
	}
} d;
bool tf[15] = {0};
void chk(){
	long long tot = 0, ad = cur;
	for(int i = 1;i <= cur;i++)
		ed[i] = nw[i];
	for(int i = 1;i <= k;i++)
		if(tf[i] == 1){
			tot += c[i];
			for(int j = 1;j <= n;j++)
				ad++, ed[ad] = (Edge){n + i, j, a[j][i]};
		}
	d.pre(n + 20);
	sort(ed + 1, ed + ad + 1);
	cnt = n + (ad - cur) / n;
	for(int i = 1;i <= ad;i++){
		if(d.fnd(ed[i].u) != d.fnd(ed[i].v)){
			cnt--, tot += ed[i].w;
			d.mrg(ed[i].u, ed[i].v);
		}
		if(cnt == 1)
			break;
	}
	ans = min(ans, tot);
	return ;
}
void srh(long long x){
	if(x == k + 1){
		chk();
		return ;
	}
	if(c[x] != 0)
		tf[x] = 0, srh(x + 1);
	tf[x] = 1, srh(x + 1);
	return ;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1, a, b, c;i <= m;i++){
		cin >> a >> b >> c;
		e[i] = (Edge){a, b, c};
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++)
			cin >> a[j][i];
	}
	d.pre(n);
	sort(e + 1, e + m + 1);
	cnt = n, cur = 0;
	for(int i = 1;i <= m;i++){
		if(d.fnd(e[i].u) != d.fnd(e[i].v)){
			cnt--, cur++, nw[cur] = e[i];
			d.mrg(e[i].u, e[i].v);
		}
		if(cnt == 1)
			break;
	}
	srh(1);
	cout << ans << endl;
	return 0;
} 
