#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 5,L = 2.5e6 + 5,base = 131,mod1 = 1e9 + 7,mod2 = 201110047,inv1 = 190839696,inv2 = 7675956;
bool st;
int n,q,trie[L][26],nxt[L],cnt,ans[N];
struct node{ll hsh;int pos;};
vector<node> v[L];
vector<int> g[L];
vector<ll> tval[L];
string s1,s2;
queue<int> q2;
struct Hash{
	int head[L],cnt;
	struct node{ll val;int num,nxt;}v[L];
	int& operator[](ll x){
		int hsh = x % L;
		for(int i = head[hsh];i;i = v[i].nxt){
			if(v[i].val == x)return v[i].num;
		}
		v[++cnt] = {x,0,head[hsh]},head[hsh] = cnt;
		return v[cnt].num;
	}
}mp;
bool en;
ll get(int x,int y){return 1ll * x * mod2 + y;}
pair<int,int> get(const string &s){
	int val1 = 0,val2 = 0;
	for(auto i : s){
		val1 = (1ll * val1 * base + i) % mod1;
		val2 = (1ll * val2 * base + i) % mod2;
	}
	return make_pair(val1,val2);
}
void insert(){
	pair<int,int> hsh1 = get(s1),hsh2 = get(s2);
	ll dlt = get(((ll)hsh2.first + mod1 - hsh1.first) % mod1,(hsh2.second + mod2 - hsh1.second) % mod2),pos = 0;
	for(auto i : s1){
		int t = i - 'a';
		if(!trie[pos][t])trie[pos][t] = ++cnt;
		pos = trie[pos][t];
	}
	tval[pos].push_back(dlt);
}
void build(){
	for(int i = 0;i < 26;i++){
		if(trie[0][i])q2.push(trie[0][i]);
	}
	while(!q2.empty()){
		int u = q2.front();q2.pop();
		g[nxt[u]].push_back(u);
		for(int i = 0;i < 26;i++){
			if(!trie[u][i])trie[u][i] = trie[nxt[u]][i];
			else nxt[trie[u][i]] = trie[nxt[u]][i],q2.push(trie[u][i]);
		}
	}
}
void solve(int qwq){
	pair<int,int> hsh1 = get(s1),hsh2 = get(s2);
	int pos = 0,now1 = 1,now2 = 1,dlt1 = ((ll)hsh2.first + mod1 - hsh1.first) % mod1,dlt2 = (hsh2.second + mod2 - hsh1.second) % mod2;
	for(int i = 1;i < s1.size();i++){
		now1 = 1ll * now1 * inv1 % mod1;
		now2 = 1ll * now2 * inv2 % mod2;
	}
	for(auto i : s1){
		pos = trie[pos][i - 'a'];
		v[pos].push_back({get(1ll * dlt1 * now1 % mod1,1ll * dlt2 * now2 % mod2),qwq});
		now1 = 1ll * now1 * base % mod1;
		now2 = 1ll * now2 * base % mod2;
	}
}
void dfs(int pos){
	for(auto i : tval[pos])mp[i]++;
	for(auto i : v[pos])ans[i.pos] += mp[i.hsh];
	for(auto i : g[pos])dfs(i);
	for(auto i : tval[pos])mp[i]--;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1 >> s2;
		insert();
	}
	build();
	for(int i = 1;i <= q;i++){
		cin >> s1 >> s2;
		if(s1.size() == s2.size())solve(i);
	}
	dfs(0);
	for(int i = 1;i <= q;i++)cout << ans[i] << endl;
}
