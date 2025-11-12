#include<bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5, M = 2.5e6 + 5;


struct node {
	int son[26];
	bool med;
	vector <int> ed;
	//vector <pair <int, int> > times;
};

string s[N][2], t[2];
node ac[M][2];
int cnt[2], nxt[M][2], clen[N], tlen, lst, fst;

void add (int x) {
	int now[2] = {0, 0}, len = s[x][0].size ();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j <= 1; ++j) {
			if (ac[now[j]][j].son[s[x][j][i] - 'a'] == 0) ac[now[j]][j].son[s[x][j][i] - 'a'] = ++cnt[j];
			now[j] = ac[now[j]][j].son[s[x][j][i] - 'a'];
		}
	}
	for (int j = 0; j <= 1; ++j) ac[now[j]][j].ed.push_back (x), ac[now[j]][j].med = 1;
} 

void build () {
	queue <int> q;
	int now, v;
	for (int i = 0; i < 26; ++i) if (ac[0][0].son[i] != 0) q.push (ac[0][0].son[i]);
	while (!q.empty ()) {
		now = q.front (), q.pop ();
		for (int i = 0; i < 26; ++i) {
			v = ac[now][0].son[i];
			if (v == 0) ac[now][0].son[i] = ac[nxt[now][0]][0].son[i];
			else {
				//if (v == 10) cout << "sp3 " << now << " " << nxt[now][0] << endl;
				nxt[v][0] = ac[nxt[now][0]][0].son[i], q.push (v), ac[v][0].med |= ac[nxt[v][0]][0].med;
			}
		}
	}
	for (int i = 0; i < 26; ++i) if (ac[0][1].son[i] != 0) q.push (ac[0][1].son[i]);
	while (!q.empty ()) {
		now = q.front (), q.pop ();
		for (int i = 0; i < 26; ++i) {
			v = ac[now][1].son[i];
			if (v == 0) ac[now][1].son[i] = ac[nxt[now][1]][1].son[i];
			else nxt[v][1] = ac[nxt[now][1]][1].son[i], q.push (v), ac[v][1].med |= ac[nxt[v][1]][1].med;
		}
	}
}

int query () {
	set <int> stk[2];
	int now[2] = {0, 0}, temp[2], ans = 0;
	for (int i = 0; i < tlen; ++i) {
		//++ac[now[0]][0].times, ++ac[now[1]][1].times;
		//cout << now[0] << " " << now[1] << endl;
		if (i > lst) {
			if (ac[now[0]][0].med != 0 && ac[now[1]][1].med != 0) {
				//cout << "sp1 " << now[0] << " " << now[1] << endl;
				for (int j = 0; j <= 1; ++j) {
					temp[j] = now[j];
					while (temp[j] != 0) {
						//cout << j << " " << temp[j] << endl;
						for (auto k : ac[temp[j]][j].ed) if (clen[k] >= i - fst) stk[j].insert (k);
						temp[j] = nxt[temp[j]][j];
					}
				}
				//cout << "sp2 " << endl;
				for (auto i : stk[0]) if (stk[1].count (i) > 0) ++ans;
				stk[0].clear (), stk[1].clear ();
			}
			/*temp[0] = n
			while (now[0] )
			ac[now[0]][0].times.push_back ({pl, i - fst + 1});
			ac[now[1]][1].times.push_back ({pl, i - fst + 1});*/
		}
		for (int j = 0; j < 2; ++j) now[j] = ac[now[j]][j].son[t[j][i] - 'a'];
	}
	//cout << now[0] << " " << now[1] << endl;
	if (ac[now[0]][0].med != 0 && ac[now[1]][1].med != 0) {
		//cout << "sp1 " << now[0] << " " << now[1] << endl;
		for (int j = 0; j <= 1; ++j) {
			temp[j] = now[j];
			while (temp[j] != 0) {
				//cout << j << " " << temp[j] << endl;
				for (auto k : ac[temp[j]][j].ed) if (clen[k] >= tlen - fst) stk[j].insert (k);
				temp[j] = nxt[temp[j]][j];
			}
		}
		for (auto i : stk[0]) {
			if (stk[1].count (i) > 0) ++ans;
		}
		stk[0].clear (), stk[1].clear ();
	}
	return ans;
}

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> s[i][0] >> s[i][1], clen[i] = s[i][0].size (), add (i);
	build ();
	for (int i = 1; i <= q; ++i) {
		cin >> t[0] >> t[1], tlen = t[0].size ();
		if (t[0].size () != t[1].size ()) {
			cout << 0 << endl;
			continue;
		}
		for (int j = tlen - 1; j >= 0; --j) {
			if (t[0][j] != t[1][j]) {
				lst = j;
				break;
			}
		}
		for (int j = 0; j < tlen; ++j) {
			if (t[0][j] != t[1][j]) {
				fst = j;
				break;
			}
		}
		cout << query () << endl;
	}
	return 0;
}
