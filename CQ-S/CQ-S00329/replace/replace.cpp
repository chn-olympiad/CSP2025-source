#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define db double
#define str string
#define MP make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ms(a,t) memset(a,t,sizeof(a))
#define lowbit(x) ((x)&(-(x)))
const int maxn = 6e6+10;
const int maxm = 2e5+10;
const ll INF = 0x3f3f3f3f;
const db eps = 1e-6;
const int mod = 1e9+7;
struct AC {
	int nxt[maxn][27],cnt[maxn];
	int tot = 0;
	void init() {
		for(int i = 0; i <= tot; i++) { for(int j = 0; j <= 26; j++) { nxt[i][j] = 0; } cnt[i] = 0; }
		tot = 0;
		return;
	}
	void add(str &x) {
		int p = 0;
		for(int i = 0; i < (int)x.size(); i++) {
			int c = ((x[i] == '#') ? 26 : (x[i]-'a'));
			if(!nxt[p][c]) nxt[p][c] = ++tot;
			p = nxt[p][c];
		}
		cnt[p]++;
	}
	int pre[maxn];
	void build() {
		queue<int> q;
		for(int i = 0; i <= 26; i++) if(nxt[0][i]) q.push(nxt[0][i]);
		while(!q.empty()) {
			int x = q.front(); q.pop();
			cnt[x] += cnt[pre[x]];
			for(int i = 0; i <= 26; i++) {
				int &to = nxt[x][i];
				if(!to) {
					to = nxt[pre[x]][i];
				} else {
					pre[to] = nxt[pre[x]][i];
					q.push(to);
				}
			}
		}
	}
	ll query(str &x) {
		ll ret = 0;
		int p = 0;
		for(int i = 0; i < (int)x.size(); i++) {
			int c = ((x[i] == '#') ? 26 : (x[i]-'a'));
			p = nxt[p][c];
			ret += cnt[p];
		}
		return ret;
	}
}tr;
str work(str &x,str &y) {
	int l = 0,r = x.size();
	while(l < r && x[l] == y[l]) l++;
	while(l < r && x[r-1] == y[r-1]) r--;
	str tmp = x.substr(0,l)+'#'+x.substr(l,r-l)+'#'+y.substr(l,r-l)+'#'+x.substr(r,x.size()-r);
	return tmp;
}
int n,q;
void Solve() {
	cin >> n >> q;
	str x,y;
	for(int i = 1; i <= n; i++) {
		cin >> x >> y;
		str tmp = work(x,y);
		tr.add(tmp);
//		cerr<<tmp<<'\n';
	}
	tr.build();
	for(int i = 1; i <= q;i++){
		cin >> x >> y;
		str tmp = work(x,y);
		cout<<tr.query(tmp)<<'\n';
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cerr<<(string("ab").substr(0,0));
//	cerr<<sizeof(tr)/1024.0/1024<<'\n';
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	int tt; cin >> tt; while(tt--)
	Solve();
	return 0;
}
