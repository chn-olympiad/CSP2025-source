#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;
const int N = 5.5E6;
const uint MOD = 998244353;
const uint base = 133331;

inline int to_int(char c) {
	return c == '#' ? 0 : c - 'a' + 1;
}

struct Node {
	Node* son[27];
	Node* nxt;
	int cnt;
	Node() {
		for(int i = 0; i <= 26; i ++) son[i] = nullptr;
		nxt = nullptr;
		cnt = 0;
	}
} tree[N];

vector<Node*> nxt_son[N];

inline bool is_root(Node* x) {
	return x->nxt == x;
}

unordered_map<uint, Node*> find_root;

int n, q, tot;

pair<string, uint> prep(string* str1, string* str2) {
	string x = *str1, y = *str2;
	string coic = "";
	int l = -1, r = x.size();
	while(x[l+1] == y[l+1]) l++;
	while(x[r-1] == y[r-1]) r--;
	for(int i = 0; i <= l; i ++) coic += x[i];
	coic += '#';
	for(int i = r; i < (int)x.size(); i ++) coic += y[i];
	uint id = 0, pow = 1;
	for(int i = l+1; i <= r-1; i ++) {
		id = (id + 1LL * pow * to_int(x[i])) % MOD;
		pow = 1LL * pow * base % MOD;
	}
	for(int i = l+1; i <= r-1; i ++) {
		id = (id + 1LL * pow * to_int(y[i])) % MOD;
		pow = 1LL * pow * base % MOD;
	}
	return make_pair(coic, id);
}

void build(string* str, Node* root) {
	string x = *str;
	Node* v = root;
	for(int i = 0; i < (int)x.size(); i ++) {
		int num = to_int(x[i]);
		if(v->son[num]) v = v->son[num];
		else v = v->son[num] = &tree[++tot];
	}
	v->cnt ++;
}

void compute_nxt(Node* v) {
	vector<Node*> tmp = {};
	for(int i = 0; i <= 26; i ++) 
		if(v->son[i]) v->son[i]->nxt = v->nxt->son[i], tmp.emplace_back(v->son[i]);
		else v->son[i] = v->nxt->son[i];
	for(Node* u : tmp) compute_nxt(u);
}

void topo() {
	for(int i = 1; i <= tot; i ++) 
		if(!is_root(&tree[i])) nxt_son[tree[i].nxt - tree].emplace_back(&tree[i]);
	queue<Node*> q;
	for(int i = 1; i <= tot; i ++) 
		if(is_root(&tree[i])) q.push(&tree[i]);
	while(!q.empty()) {
		Node* v = q.front(); q.pop();
		for(Node* u : nxt_son[v - tree]) u->cnt += v->cnt, q.push(u);
	}
}

int query(string* str, Node* root) {
	string x = *str;
	Node* v = root;
	int sum = 0;
	for(int i = 0; i < (int)x.size(); i ++) {
		int num = to_int(x[i]);
		v = v->son[num];
		sum += v->cnt;
	}
	return sum;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> q;
	string str1, str2;
	
	for(int i = 1; i <= n; i ++) {
		cin >> str1 >> str2;
		if(str1 != str2) {
			pair<string, uint> tmp = prep(&str1, &str2);
			string coic = tmp.first;
			int id = tmp.second;
			if(find_root.find(id) == find_root.end()) {
				find_root[id] = &tree[++tot];
				tree[tot].nxt = &tree[tot];
			}
			build(&coic, find_root[id]);
		}
	}
	
	for(int i = 1; i <= tot; i ++) 
		if(is_root(&tree[i])) {
			vector<Node*> tmp = {};
			for(int j = 0; j <= 26; j ++) 
				if(!tree[i].son[j]) tree[i].son[j] = &tree[i];
				else tree[i].son[j]->nxt = &tree[i], tmp.emplace_back(tree[i].son[j]);
			for(Node* u : tmp) compute_nxt(u);
		}
	
//	topo();
//	for(int i = 1; i <= 5; i ++) cout << tree[i].nxt - tree << ' ';
	
//	for(int i = 1; i <= q; i ++) {
//		cin >> str1 >> str2;
//		if(str1.size() != str2.size()) cout << "0\n";
//		else {
//			pair<string, uint> tmp = prep(&str1, &str2);
//			string coic = tmp.first;
//			int id = tmp.second;
//			if(find_root.find(id) == find_root.end()) cout << "0\n";
//			else cout << query(&coic, find_root[id]) << '\n';
//		}
//	}
	return 0;
}


