#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)
#define pb emplace_back
#define fi first
#define se second
using vi = vector<int>;
using pi = pair<int, int>;

template<typename T0, typename T1> bool chmin(T0 &x, const T1 &y){
	if(y < x){x = y; return true;} return false;
}
template<typename T0, typename T1> bool chmax(T0 &x, const T1 &y){
	if(x < y){x = y; return true;} return false;
}

template<typename T> void debug(char *s, T x){
	cerr << s <<" = "<< x << endl;
}
template<typename T, typename ...Ar> void debug(char *s, T x, Ar... y){
	int dep = 0;
	while(!(dep == 0 && *s == ',')){
		if(*s == '(') dep ++;
		if(*s == ')') dep --;
		cerr << *s ++;
	}
	cerr << " = " << x << ",";
	debug(s + 1, y...);
}
#define gdb(...) debug((char*)#__VA_ARGS__, __VA_ARGS__)

array<string, 4> F(string a, string b){
	int i = 0, j = a.size();
	while(a[i] == b[i]){
		i ++;
	}
	while(a[j - 1] == b[j - 1]){
		j --;
	}
	return {a.substr(0, i), a.substr(i, j - i), b.substr(i, j - i), a.substr(j)};
}

struct trie{
	vector< array<int, 27> > s;
	vi id;
	int tot, cid;

	trie(int n){
		s.resize(n, {});
		id.resize(n, -1);
		tot = 2, cid = 0;
	}
	void ins(string str){
		int u = 1;
		for(char c:str){
			int d = c - 'a';
			if(s[u][d] == 0){
				s[u][d] = tot ++;
			}
			u = s[u][d];
		}
		if(id[u] == -1){
			id[u] = cid ++;
		}
	}
	int sid(string str){
		int u = 1;
		for(char c:str){
			int d = c - 'a';
			if(s[u][d] == 0){
				return -1;
			}
			u = s[u][d];
		}
		return id[u];
	}
};

struct acam{
	vector< array<int, 27> > s;
	vi fa, rt, sum;
	int tot;

	acam(int n){
		s.resize(n);
		fa.resize(n);
		rt.resize(n);
		sum.resize(n);
		tot = 1;
	}
	void ins(int rid, string str){
		if(!rt[rid]){
			rt[rid] = tot ++;
		}
		int u = rt[rid];
		for(char c:str){
			int d = c - 'a';
			if(s[u][d] == 0){
				s[u][d] = tot ++;
			}
			u = s[u][d];
		}
		sum[u] ++;
	}
	void build(){
		rep(i, 0, int(rt.size()) - 1){
			if(rt[i] == 0){
				continue;
			}
			static queue<int> Q;
			Q.emplace(rt[i]);
			while(Q.size()){
				int u = Q.front();
				Q.pop();
				rep(c, 0, 26){
					if(s[u][c]){
						fa[ s[u][c] ] = (u == rt[i]? rt[i]: s[ fa[u] ][c]);
						Q.emplace(s[u][c]);
					} else{
						s[u][c] = (u == rt[i]? rt[i]: s[ fa[u] ][c]);
					}
				}
				if(u != rt[i]){
					sum[u] += sum[ fa[u] ];
				}
			}
		}
	}
	int qry(int rid, string str){
		int u = rt[rid];
		int res = 0;
		for(char c:str){
			int d = c - 'a';
			u = s[u][d];
			res += sum[u];
		}
		return res;
	}
};

void solve(){
	int n, q;
	cin >> n >> q;

	vector< array<string, 4> > a;

	int sumlen = n * 10 + 5;
	rep(i, 0, n - 1){
		string x, y;
		cin >> x >> y;
		if(x == y){
			continue;
		}
		a.pb(F(x, y));
		sumlen += x.size() + y.size();
	}

	trie T(sumlen);
	rep(i, 0, int(a.size()) - 1){
		T.ins(a[i][1] + "{" + a[i][2]);
	}
	acam M(sumlen);
	rep(i, 0, int(a.size()) - 1){
		int rid = T.sid(a[i][1] + "{" + a[i][2]);
		M.ins(rid, a[i][0] + "{" + a[i][3]);
	}
	M.build();

	rep(i, 0, q - 1){
		string x, y;
		cin >> x >> y;
		if(x.size() != y.size()){
			cout << 0 <<'\n';
			continue;
		}
		array<string, 4> t = F(x, y);
		int rid = T.sid(t[1] + "{" + t[2]);
		if(rid == -1){
			cout << 0 <<'\n';
			continue;
		}
		int ans = M.qry(rid, t[0] + "{" + t[3]);
		cout << ans <<'\n';
	}
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
