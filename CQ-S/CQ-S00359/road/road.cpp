#include <bits/stdc++.h>
#define int long long
using namespace std;
bool ST;
constexpr int N=2e4+5, M=1e6+5, K=11;
int n, m, k, c[K];
int a[K][N];
tuple<int, int, int> e[M], e2[M];
int fd[N];
int find(int v) {
	return fd[v]==v?v:fd[v]=find(fd[v]);
}
inline bool merg(int u,int v) {
	if((u=find(u))==(v=find(v))) return 0;
	fd[u]=v;
	return 1;
}
bool ED;
signed main() {
//	cerr<<(&ED-&ST)/1e6<<" M"<<endl;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>get<1>(e[i])>>get<2>(e[i])>>get<0>(e[i]);
	sort(e+1, e+m+1);
	for(int i=1;i<=k;++i) {
		cin>>c[i];
		for(int j=1;j<=n;++j) {
			cin>>a[i][j];
//			a[i][j].second=j;
		}
//		sort(a[i]+1, a[i]+n+1);
	}
	int res=1e18;
	for(int s=0;s<(1<<k);++s) {
		int p=1, cnt=0;
		iota(fd, fd+(n<<1)+1, 0);
		copy(e+1, e+m+1, e2+1);
		int tot=0, pc=0;
		for(int i=1;i<=k;++i)
			if((s>>(i-1))&1) {
				cnt+=c[i];
				++pc;
				for(int j=1;j<=n;++j)
					e2[++tot]=tuple<int, int, int>{a[i][j], n+i, j};
			}
		sort(e2+1, e2+tot+1);
		int left=n+pc;
		for(int p1=1, p2=1;p1<=m || p2<=tot;) {
			int w, u, v;
//			cerr<<"P!@ "<<p1<<" "<<p2<<"  "<<get<0>(e[p1])<<" "<<get<0>(e2[p2])<<endl;
			if(p1<=m && get<0>(e[p1])<get<0>(e2[p2]))
				tie(w, u, v)=e[p1++];
			else
				tie(w, u, v)=e2[p2++];
			if(merg(u, v)) {
				if((cnt+=w)>=res) goto END;
				if(--left==1)	break;
			}
		}
//		cerr<<"CNT "<<cnt<<endl;
		res=min(res, cnt);
		END:;
	}
	cout<<res;
	return 0;
}

