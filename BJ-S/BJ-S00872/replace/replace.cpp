#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef unsigned long long ull;
const int N = 5e5 + 7;
string s1, s2, t1, t2;
map <pair<ull, ull>, int> mp;
int n, q, cnt, tot, ans;
int rt1[N], rt2[N], use[N];

struct Tree{
	int ch[30];
	vector <int> adj;
}tr[N*10];

void Insert(int fst, int lst, int now, int id){
	int p1 = rt1[now], p2 = rt2[now];
	for(int i = fst - 1; i >= 0; --i){
		int c = s1[i] - 'a';
		if(!tr[p1].ch[c]) tr[p1].ch[c] = ++tot;
		p1 = tr[p1].ch[c];
	}
	tr[p1].adj.push_back(id);
	for(int i = lst + 1; i < s1.size(); ++i){
		int c = s1[i] - 'a';
		if(!tr[p2].ch[c]) tr[p2].ch[c] = ++tot;
		p2 = tr[p2].ch[c];
	}
	tr[p2].adj.push_back(id);
}

void Find(int fst, int lst, int now){
	int p1 = rt1[now], p2 = rt2[now]; ans = 0;
	for(int i = fst - 1; i >= 0; --i){
		for(int j = 0; j < tr[p1].adj.size(); ++j) use[tr[p1].adj[j]] = 1;
		int c = t1[i] - 'a';
		if(!tr[p1].ch[c]) break;
		p1 = tr[p1].ch[c];
	}
	for(int j = 0; j < tr[p1].adj.size(); ++j) use[tr[p1].adj[j]] = 1;
	for(int j = 0; j < tr[p2].adj.size(); ++j) if(use[tr[p2].adj[j]] == 1) ans++;
	for(int i = lst + 1; i < t1.size(); ++i){
		int c = t1[i] - 'a';
		if(!tr[p2].ch[c]) break;
		p2 = tr[p2].ch[c];
		for(int j = 0; j < tr[p2].adj.size(); ++j) if(use[tr[p2].adj[j]] == 1) ans++;
	}
	p1 = rt1[now];
	for(int i = fst - 1; i >= 0; --i){
		for(int j = 0; j < tr[p1].adj.size(); ++j) use[tr[p1].adj[j]] = 0;
		int c = t1[i] - 'a';
		if(!tr[p1].ch[c]) break;
		p1 = tr[p1].ch[c];
	}
	for(int j = 0; j < tr[p1].adj.size(); ++j) use[tr[p1].adj[j]] = 0;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> s1 >> s2;
		if(s1 == s2) continue;
		int fst, lst;
		for(int j = 0; j < s1.size(); ++j){
			if(s1[j] != s2[j]){
				fst = j;
				break;
			}
		}
		for(int j = s1.size() - 1; j >= 0; --j){
			if(s1[j] != s2[j]){
				lst = j;
				break;
			}
		}
		ull hs1 = 0, hs2 = 0;
		for(int j = fst; j <= lst; ++j){
			hs1 = hs1 * 37 + (s1[j] - 'a');
			hs2 = hs2 * 53 + (s2[j] - 'a');
		}
		pair<ull, ull> tmp = {hs1, hs2};
		if(mp[tmp] == 0) mp[tmp] = ++cnt, rt1[cnt] = ++tot, rt2[cnt] = ++tot;
		Insert(fst, lst, mp[tmp], i);
	}
	while(q--){
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << "0\n";
			continue;
		}
		int fst, lst;
		for(int j = 0; j < t1.size(); ++j){
			if(t1[j] != t2[j]){
				fst = j;
				break;
			}
		}
		for(int j = t1.size() - 1; j >= 0; --j){
			if(t1[j] != t2[j]){
				lst = j;
				break;
			}
		}
		ull hs1 = 0, hs2 = 0;
		for(int j = fst; j <= lst; ++j){
			hs1 = hs1 * 37 + (t1[j] - 'a');
			hs2 = hs2 * 53 + (t2[j] - 'a');
		}
		pair<ull, ull> tmp = {hs1, hs2};
		if(mp[tmp] == 0){
			cout << "0\n";
			continue;
		}
		Find(fst, lst, mp[tmp]);
		cout << ans << "\n";
	}
	return 0;
}