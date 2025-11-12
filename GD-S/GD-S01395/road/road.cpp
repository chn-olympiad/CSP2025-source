#include<bits/stdc++.h> 
#define int long long
#define up(i,l,r) for(int i=l; i<=r; ++i)
#define dn(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back

using namespace std;

const int N=20205, M=2000005, K=15;

int n, m, tot, k, dsu[N], val[K], Ans=1e18;
struct node {
	int u, v, w;
	bool operator<(const node &rhs) const { return w<rhs.w; }
} sav[M], p[N], q[N]; 

int get(int x) { return x==dsu[x]?x:dsu[x]=get(dsu[x]); }

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	up(i,1,m) cin >> sav[i].u >> sav[i].v >> sav[i].w;
	sort(sav+1,sav+1+m);
	up(i,1,n) dsu[i]=i;
	up(i,1,m) {
		int x=get(sav[i].u), y=get(sav[i].v);
		if(x!=y) p[++tot]=sav[i], dsu[x]=y;
	}
	int pos=0;
	up(j,1,k) {
		int len=0;
		cin >> val[j];
		up(i,1,n) {
			int tmp; cin >> tmp;
			q[++len]=(node){i,n+j,tmp};
		}
		up(i,1,tot) q[++len]=p[i];
		up(i,1,n+k) dsu[i]=i;
		sort(q+1,q+1+len);
		up(i,1,len) {
			int x=get(q[i].u), y=get(q[i].v);
			if(x!=y) {
				dsu[x]=y;
				if(q[i].v==n+j) sav[++pos]=q[i];
			}
		}
	}
	up(i,1,tot) sav[++pos]=p[i];
	sort(sav+1,sav+1+pos);
	up(s,0,(1<<k)-1) {
		int res=0;
		up(i,1,k) if(s>>(i-1)&1) res+=val[i];
		up(i,1,n+k) dsu[i]=i;
		up(i,1,pos) {
			if(sav[i].v>n&&!(s>>(sav[i].v-n-1)&1)) continue;
			int x=get(sav[i].u), y=get(sav[i].v);
			if(x!=y) dsu[x]=y, res+=sav[i].w;
		}
		Ans=min(Ans,res);
	}
	cout << Ans << '\n';
	return 0;
}
