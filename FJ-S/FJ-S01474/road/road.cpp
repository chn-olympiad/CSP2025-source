// Genshin Impact Start!!

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e6+5;
typedef long long ll;

struct E {
	int u,v;ll w;
}e[N];
int tot;

ll c[15],a[15][20005];
E ne[15][20005];
int f[20005];
int find (int x) {
	return f[x]==x?x:f[x] = find(f[x]);
}

int n,m,k;
bool cmp (E a,E b) {
	return a.w < b.w;
}

ll ans = 0,ret = 0;
void Kr () {
	sort(e+1,e+tot+1,cmp);
	for (int i = 1;i <= n;i++) 
		f[i] = i;
	int cnt = 0;
	for (int i = 1;i <= tot;i++) {
		int a = find(e[i].u),b = find(e[i].v);
		if (a == b) continue;
		f[a] = b;
		ans += e[i].w;
		++cnt;
		if (cnt == n-1) break;
	}
}

vector<int> chs;
namespace A {
	ll ret = 0;
	ll res = 0;
	int cnt = 0,nk = 0;
	void work (int u,int v,ll w) {
		int a = find(u),b = find(v);
		if (a == b) return;
		//if (u > n || v > n) puts("got 1");
		f[a] = b;
		res += w;
		++cnt;
	}
	E ade[N];int adk;
	int nw[15];
	void cal_add (ll w) {
		int mni = -1;
		while (mni == -1 || ne[mni][nw[mni]].w <= w) {
			int mni = -1;
			for (int j : chs) {
				if (nw[j] == n + 1) continue;
				if (mni == -1) mni = j;
				else if (ne[j][nw[j]].w < ne[mni][nw[mni]].w) 
					mni = j;
			}
			E tmp = ne[mni][nw[mni]];
			if (tmp.w > w) return;
			work(tmp.u,tmp.v,tmp.w);
			nw[mni]++;
			if (cnt == n+nk-1) return;
		}//puts("qwq");
	}
	void cal () {
		for (int i = 1;i <= n+k;i++) 
			f[i] = i;
		for (int j : chs) nw[j] = 1;
		cnt = 0;
	//	int r = 1;
		for (int i = 1;i <= tot;i++) {
			cal_add(e[i].w);
//			while (r <= adk && ade[r].w < e[i].w) {
//				work(ade[r].u,ade[r].v,ade[i].w);
//				r++;
//			}
			work(e[i].u,e[i].v,e[i].w);
			if (cnt == n+nk-1) break;
		}
	}
	
//	int use_pre;
//	void pre () {
//		int fin = 0,nd = chs.size();
//		while (fin != nd) {
//			int mni = -1;
//			for (int j : chs) {
//				if (nw[j] == n + 1) continue;
//				if (mni == -1) mni = j;
//				else if (ne[j][nw[j]].w < ne[mni][nw[mni]].w) 
//					mni = j;
//			}
//			ade[++adk] = ne[mni][nw[mni]];
//			nw[mni]++;
//			if (nw[mni] == n+1) fin++;
//		}
//		//printf("%d\n",++use_pre);
//		for (int j : chs) {
//			for (int i = 1;i <= n;i++) 
//				ade[++adk] = ne[j][i]; 
//		}
//		sort(ade+1,ade+adk+1,cmp);
//	}
	void solve () {
		for (int j : chs) nw[j] = 1;
		ret = ans;
		for (int s = 1;s < (1<<k);s++) {
			chs.clear();
			res = 0;nk = 0;
			for (int i = 1;i <= k;i++) {
				if (!((s>>(i-1))&1)) continue;
				res += c[i];
				chs.push_back(i);
				nk++;
			}
			//pre();
			cal();
			ret = min(ret,res);
		}
		printf("%lld\n",ret);
	}
}
int main () {
	//freopen("road1.in","r",stdin);
	//freopen("road.out","w",stdout);	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= m;i++) 
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	
	tot = m;
	Kr();
	if (k == 0) {
		printf("%lld\n",ans);
		return 0;
	}
	for (int i = 1;i <= k;i++) {
		scanf("%lld",&c[i]);
		for (int j = 1;j <= n;j++) {
			scanf("%lld",&a[i][j]);
			ne[i][j] = (E){n+i,j,a[i][j]};
		}
		sort(ne[i]+1,ne[i]+n+1,cmp);
	}
	//if (m <= 1000000) {
		A::solve();
		return 0;
	//}
	return 0;	
}
