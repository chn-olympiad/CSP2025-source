#include<bits/stdc++.h>

/*

C(n,m).cpp

#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=500005,mod=998244353;

int fac[N],inv[N];

int qmod(int n,int k) {
	if(k==0) return bool(n);
	if(k&1) return qmod(n*n%mod,k/2)*n%mod;
	else return qmod(n*n%mod,k/2);
}

void init(int n=500002) {
	fac[0]=1;
	for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	inv[n] = qmod(fac[n],mod-2);
	for(int i=n;i>=1;--i) inv[i-1]=inv[i]*i%mod;
}

int C(int n,int m) {
	if(m>n) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

signed main() {
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	init();

	return 0;
}

graph_in.cpp

#include<bits/stdc++.h>

using namespace std;

const int N=500005;

int n,m;
vector<int> vec[N];

int main() {
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n >> m;

	int u,v;
	for(int i=1;i<=m;++i) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	

	return 0;
}

temp.cpp

#include<bits/stdc++.h>

using namespace std;

int main() {
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	return 0;
}

temp_longlong.cpp

#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	return 0;
}

T.cpp

#include<bits/stdc++.h>

using namespace std;

int T;

void solve() {
	
}

int main() {
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> T;
	while(T--) solve();

	return 0;
}

LCA.cpp

#include<bits/stdc++.h>

using namespace std;

const int N=500005;

int n,m;
vector<int> vec[N];

int fa[N][22],dep[N];
void dfs1(int u,int father) {
	fa[u][0] = father,dep[u] = dep[father]+1;
	for(int i=1;i<=20;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto& v:vec[u]) {
		if(v==father) continue;
		dfs1(v,u);
	}
}

int LCA(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;--i)
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;--i)
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int main() {
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> n >> m;

	int u,v;
	for(int i=1;i<=m;++i) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	dfs1(1,0);

	return 0;
}

----------------------------

TLEWA luogu uid 515129
CSP 2025 rp++

----------------------------

g++ ?.cpp -o ? -O2 -std=c++14
ulimit -s 10240000

#define force_inline [[gnu::force_inline]] inline

----------------------------

2:45 AC T1
3:33 AC T2 too slow...


*/

using namespace std;

// max ans < 2e9

const int N = 100005;

int T,n;
int arr[N][3],p[3],que[3][N];

inline int calc(int p) {
	return max({arr[p][0],arr[p][1],arr[p][2]})*2 - arr[p][0] - arr[p][1] - arr[p][2] + min({arr[p][0],arr[p][1],arr[p][2]});
}

void solve() {
	cin >> n;

	int ans=0;p[0]=p[1]=p[2]=0;
	for(int i=1;i<=n;++i) {
		for(int j=0;j<3;++j) cin >> arr[i][j];
		for(int j=0;j<3;++j) {
			if(max({arr[i][0],arr[i][1],arr[i][2]}) == arr[i][j]) {
				que[j][++p[j]] = i;
				break;
			}
		}
		ans += max({arr[i][0],arr[i][1],arr[i][2]});
	}

	for(int j=0;j<3;++j) {
		if(p[j]<=n/2) continue;
		sort(que[j]+1,que[j]+1+p[j],[&](int a,int b) {
			return calc(a) > calc(b);
		});
		for(int i=p[j];i>n/2;--i)
			ans-=calc(que[j][i]);
	}

	cout << ans << '\n';
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> T;
	while(T--) solve();

	return 0;
}