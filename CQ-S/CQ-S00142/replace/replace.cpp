#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

namespace Main {
  
	const int N=5e6+5;
	const int M=5e6+5;
	int n, Q, iQ;
	// 有点红
	/*
	|s1|<=2.5e6
	*/
	// string s1[N],s2[N];
	// string t1[N],t2[N];
	// int idx[N];
#define pii pair<ull,ull>
#define fi first
#define se second
#define mkp make_pair
	struct edge{
		int nxt;
		pii to;
	} e[M];
	int head[M],num;
	inline void link(int x,pii y) {e[++num]={head[x],y},head[x]=num;}
	int A[M],cur;
	ull B[M],s1[M],s2[M];

	const ull base = 91917869, mod = 998244353;
	// ll Ans[N];
	inline ull hash(string &s) {
		ull t = 0;
		for(const char&c: s) t = (t * base + c - 'a' + 1) % mod;
		// assert(t < mod);
		return t;
	}
	int sz[M];
	const ull CHASH = (ull)(4e18 * acos(0)) | 71;
	struct chash { ull operator () (const ull&x) const { return __builtin_bswap64(x * CHASH); } };
	gp_hash_table<ull, int, chash> mp;
	mt19937_64 rnd(time(0));
	const ull mask = rnd();
	inline ull shift(ull x) { x^=mask, x^=(x>>7), x^=(x<<31), x^=(x>>54), x^=mask; return x; }
	const ull mod1=1e9+7;
	inline void add(const ull&x,const ull&y) { ++mp[shift(x)*y]; }
	inline int ask(const ull&x,const ull&y) { auto it = mp.find(shift(x)*y); return (it==mp.end()?0:it->second); }
	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		cin>>n>>iQ;
		int mxs=0;
		REP(i,1,n) {
			string a1,a2;
			cin>>a1>>a2;
			link(a1.size(),mkp(hash(a1),hash(a2)));
			mxs=max(mxs,int(a1.size()));
			++sz[a1.size()];
		}
		B[0]=1;
		REP(i,1,mxs) {

			if(head[i]) A[++cur]=i;
			B[i]=B[i-1]*base%mod;
		}
		// cerr << cur << '\n';
		/*Input*/ {
			string q1,q2;
			REP(ti,1,iQ) {
				cin>>q1>>q2;
				if(q1.size()!=q2.size()) {
					// Ans[ti]=0;
					cout<<0<<'\n';
					continue;
				}
				// ++Q;
				// t1[Q]=q1,t2[Q]=q2;
				// idx[Q]=ti;
				int k1=1,k2=int(q1.size());
				while(k1<=int(q1.size()) && q1[k1-1] == q2[k1-1]) k1++;
				while(k2>=1 && q1[k2-1] == q2[k2-1]) k2--;
				// cerr << k1 << ' ' << k2 << '\n';
				// if(ti==503) {
				// 	cerr<<q1<<' '<<q2<<'\n';
				// }
				// i \in [1, k1]
				// i+len-1 \in [k2, q1.size()-1]
				REP(i,1,(int)q1.size()) {
					s1[i]=(s1[i-1]*base+q1[i-1]-'a'+1)%mod;
					s2[i]=(s2[i-1]*base+q2[i-1]-'a'+1)%mod;
				}
				ll ans=0;
				REP(_,1,cur) {
					int len=A[_];
					if(max(1,k2-len+1)>min(k1,(int)q1.size()-len+1))continue;
					int L=max(1,k2-len+1),R=min(k1,(int)q1.size()-len+1);
					if(R-L+1>=sz[len]) {
						// cerr << len << '\n';
						for(int i=head[len];i;i=e[i].nxt) {
							add(e[i].to.fi,e[i].to.se);
							// cerr << len << "UPD " << ' ' << e[i].to.fi << ' ' << e[i].to.se << '\n';
						}
						for(int i=L;i<=R; ++i) {
							// cerr << len << ' '<<ti<<' ' << "ASK " << ' ' << (s1[i+len-1]-s1[i-1]*B[len]%mod+mod)%mod << ' ' << (s2[i+len-1]-s2[i-1]*B[len]%mod+mod)%mod << '\n';
							ans+=ask((s1[i+len-1]-s1[i-1]*B[len]%mod+mod)%mod,
								(s2[i+len-1]-s2[i-1]*B[len]%mod+mod)%mod);
						}
					}
					else {
						REP(i,L,R) add((s1[i+len-1]-s1[i-1]*B[len]%mod+mod)%mod,
								(s2[i+len-1]-s2[i-1]*B[len]%mod+mod)%mod);
						for(int i=head[len];i;i=e[i].nxt)ans+=ask(e[i].to.fi,e[i].to.se);
					}
					// mp.clear();
					gp_hash_table<ull,int,chash>().swap(mp);
				}
				cout<<ans<<'\n';
			}
		}

		// 还要写 GSAM，才能 2log
		// 性价比很低
		// 不如 nsqrtn

		// REP(i,1,iQ) cout<<Ans[i]<<'\n';

		return 0;
	}
}

int main() {
#ifndef Ace
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	Main::main();
	return 0;
} 
// Think TWICE, code ONCE
// ML: 2048MB
// TL: 1s
/*
不会是 acam 吧
没调出来

nsadjhfnjhnhg
*/