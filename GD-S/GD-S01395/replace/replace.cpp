#include<bits/stdc++.h> 
#define up(i,l,r) for(int i=l; i<=r; ++i)
#define dn(i,r,l) for(int i=r; i>=l; --i)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

const int N=200005, M=2000005, K=23;
 
int n, T, P, Q, Ans[N], tr[M];
struct node { int x, y, id; } p[M<<1], q[M<<2];

struct AC {
	int tot, B, val[M], fail[M], tr[M][26];
	int dep[M], fa[M][K], L[M], R[M], stp;
	vector<int> to[M];
	int insert(string str) {
		int p=0, len=str.size();
		up(i,0,len-1) {
			int v=str[i]-'a';
			if(!tr[p][v]) tr[p][v]=++tot;
			p=tr[p][v], dep[p]=i+1;
		}
		++val[p];
		return p;
	}
	void dfs(int x) {
		L[x]=++stp;
		up(i,1,B) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(int y:to[x]) fa[y][0]=x, dfs(y);
		R[x]=stp;
	}
	void build() {
		B=log2(tot+1);
		queue<int> q;
		up(i,0,25) if(tr[0][i]) q.push(tr[0][i]);
		while(q.size()) {
			int x=q.front(); q.pop();
			up(i,0,25) {
				if(tr[x][i]) {
					q.push(tr[x][i]);
					fail[tr[x][i]]=tr[fail[x]][i];
				}
				else {
					tr[x][i]=tr[fail[x]][i];
				}
			}
		}
		up(i,1,tot) to[fail[i]].pb(i);
		dfs(0);
	}
	int jump(int x,int len) {
		if(dep[x]<len) return x;
		dn(i,B,0) if(dep[fa[x][i]]>=len) x=fa[x][i];
		return fa[x][0];
	}
} L, R;

inline void add(int x,int v) {
	for( ; x<=R.tot; x+=x&-x) tr[x]+=v;
}

inline int ask(int x) {
	int ret=0;
	for( ; x; x-=x&-x) ret+=tr[x];
	return ret;
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> T;
	vector<pii> sav;
	sav.resize(n);
	up(i,1,n) {
		string l, r;
		cin >> l >> r;
		sav[i-1].first=L.insert(l);
		sav[i-1].second=R.insert(r);
	}
	L.build(), R.build();
	for(pii u:sav) {
		int l=u.first, r=u.second;
		p[++P]=(node){R.L[r],R.R[r],-L.L[l]};
		p[++P]=(node){R.L[r],R.R[r],L.R[l]+1};
	}
	up(u,1,T) {
		string l, r;
		cin >> l >> r;
		if(l.size()!=r.size()) continue;
		int len=l.size(), pl=0, pr=0, de, fi;
		up(i,0,len-1) if(l[i]!=r[i]) { fi=i; break; }
		dn(i,len-1,0) if(l[i]!=r[i]) { de=i; break; }
		up(i,0,len-1) {
			pl=L.tr[pl][l[i]-'a'];
			pr=R.tr[pr][r[i]-'a'];
			if(i>=de) {
				int ran=(i<=fi)?1:(i-fi+1);
				int Pl=L.jump(pl,ran);
				int Pr=R.jump(pr,ran);
				q[++Q]=(node){L.L[pl],R.L[pr],u};
				q[++Q]=(node){L.L[Pl],R.L[Pr],u};
				q[++Q]=(node){L.L[pl],R.L[Pr],-u};
				q[++Q]=(node){L.L[Pl],R.L[pr],-u};
			}
		}
	}
	sort(p+1,p+1+P,[](node i,node j){return abs(i.id)<abs(j.id);});
	sort(q+1,q+1+Q,[](node i,node j){return i.x<j.x;});
	int j=1;
	up(i,1,Q) {
		while(j<=P&&abs(p[j].id)<=q[i].x) {
			if(p[j].id<0) add(p[j].x,1), add(p[j].y+1,-1);
			else add(p[j].x,-1), add(p[j].y+1,1);
			++j;
		}
		int id=q[i].id;
		if(id>0) Ans[+q[i].id]+=ask(q[i].y);
		if(id<0) Ans[-q[i].id]-=ask(q[i].y);
	} 
	up(i,1,T) cout << Ans[i] << '\n';
	return 0;
}
