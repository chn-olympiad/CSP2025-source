#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define LL long long
typedef pair<int, int> PII;
LL read(){LL x; scanf("%lld", &x); return x; }

const int N = 2e5 + 10;
const int P = 2e6 + 10;

string sta, stb;
int n, m;
vector<short> a[N], b[N];

int ans[N], mxc;
vector<int> ca[N], cb[N];
short gtch(char x, char y){return 26 * (x - 'a') + (y - 'a'); }

int cpo;
map<PII, int> tr;
int fail[P], val[P];
vector<PII> e[P];
void init(){
	tr.clear();
	for(int i = 0; i <= cpo; i ++)fail[i] = val[i] = 0, e[i].clear(), e[i].shrink_to_fit();
	cpo = 0;
}
void ins(int u){
	
//	cerr << "INS:" << u << "=======\n";
	
	int x = 0;
	for(int i = 1; i < a[u].size(); i ++){
		int c = a[u][i];
		
//		cerr << c << "->";
		
		if(!tr[{x, c}])tr[{x, c}] = ++ cpo, e[x].push_back({cpo, c});
		x = tr[{x, c}];
		
//		cerr << x << " ";
	}
	
//	cerr << "\n";
	
	val[x] ++;
}
queue<int> q;
void build(){
	q.push(0);
	while(q.size()){
		int x = q.front(); q.pop();
		for(PII t : e[x]){
			int y = t.first, c = t.second;
			int p = fail[x];
			while(1){
				fail[y] = tr[{p, c}];
				if(fail[y])break;
				if(!p)break;
				p = fail[p];
			}
			if(fail[y] == y)fail[y] = 0;
//			cerr << "FL:" << y << "->" << fail[y] << "\n";
			q.push(y);
		}
		val[x] += val[fail[x]];
	}
}
void func(int u){
	int x = 0;
	for(int i = 1; i < b[u].size(); i ++){
		int c = b[u][i];
		while(x && !tr[{x, c}])x = fail[x];//, cerr << x << "->" << fail[x] << "\n";
		if(tr[{x, c}])x = tr[{x, c}];
		
//		cerr << x << "->" << val[x] << "\n";
		
		ans[u] += val[x];
	}
}


void solve(int qid){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
    	cin >> sta >> stb;
    	int ct = 0; a[i].push_back(-1);
    	for(int j = 0; j < sta.size(); j ++)a[i].push_back(gtch(sta[j], stb[j])), ct += sta[j] != stb[j];
		ca[ct].push_back(i); mxc = max(ct, mxc);	
	}
	for(int i = 1; i <= m; i ++){
    	cin >> sta >> stb;
    	int ct = 0; b[i].push_back(-1);
    	for(int j = 0; j < sta.size(); j ++)b[i].push_back(gtch(sta[j], stb[j])), ct += sta[j] != stb[j];
		cb[ct].push_back(i);
	}
	
	for(int i = 0; i <= mxc; i ++){
		if(!ca[i].size() || !cb[i].size())continue;
		init();
		for(int u : ca[i])ins(u);
		build();
		for(int u : cb[i])func(u);
	}
	
	for(int i = 1; i <= m; i ++)printf("%d\n", ans[i]);
}

signed main(){
    int tii = 1;
    for(int z = 1; z <= tii; z ++)solve(z);
    return 0;
}
