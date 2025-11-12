#include <bits/stdc++.h>
using namespace std;
int n,q,trie[2][5000005][26],fail[2][5000005],cnt[2],tr[200005],awd[200005],le,ri;
long long res;
vector <int> cntword[2][5000005];
string A,B;
map <string,map<string,int>> p;
inline void insert(string s,int t,int id){
	int root = 0;
	for (int i = 0;i < s.size();++i){
		if (!trie[t][root][s[i] - 'a']) trie[t][root][s[i] - 'a'] = ++cnt[t];
		root = trie[t][root][s[i] - 'a'];
	}
	cntword[t][root].push_back(id);
}
inline void getFail(int t){
	queue <int> q;
	for (int i = 0;i < 26;++i) if (trie[t][0][i]) q.push(trie[t][0][i]);
	while (!q.empty()){
		int tmp = q.front();
		q.pop();
		for (int i = 0;i < 26;++i){
			if (trie[t][tmp][i]) fail[t][trie[t][tmp][i]] = trie[t][fail[t][tmp]][i],q.push(trie[t][tmp][i]);
			else trie[t][tmp][i] = trie[t][fail[t][tmp]][i];
		}
	} 
}
inline void solve(){
	set <int> sp;
	int rootA = 0,rootB = 0;
	for (int i = 0;i < A.size();++i) if (A[i] != B[i]) le = min(le,i),ri = i;
	for (int i = 0;i < A.size();++i){
		rootA = trie[1][rootA][B[i] - 'a'];
		rootB = trie[0][rootB][A[i] - 'a'];
		if (i < ri) continue;
		for (int j = rootA;j;j = fail[1][j]) for (int k:cntword[1][j]) if (i - tr[k] + 1 <= le) sp.insert(k);
		for (int j = rootB;j;j = fail[0][j]) for (int k:cntword[0][j]) if (sp.count(k)) res += awd[k];
		sp.clear();
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;++i){
		cin >> A >> B;
		if (p[A][B]) ++awd[p[A][B]];
		else{
			p[A][B] = i,awd[i] = 1,tr[i] = A.size();
			insert(A,0,i),insert(B,1,i);
		}
	}
	getFail(0),getFail(1);
	while (q--){
		cin >> A >> B;
		le = 2147483647,ri = res = 0;
		solve();
		cout << res << "\n";
 	}
 	return 0;
}
