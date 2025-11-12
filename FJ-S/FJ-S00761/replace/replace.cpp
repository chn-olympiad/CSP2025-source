#include<bits/stdc++.h>
using namespace std;

struct Node {
	vector<string> s2;
	int nxt[27];
};

struct Trie {
	vector<Node> v;
	
	void init() {
		Node temp;
		memset(temp.nxt, 0, sizeof(temp.nxt));
		v.push_back(temp);
	}
	
	void add(string s1, string s2) {
		int i = 0;
		for (char c: s1) {
			int num = c - 'a' + 1;
			//cout << c << ' ' << num << ' ' << v[i].nxt[num] << endl;
			if (v[i].nxt[num] == 0) {
				Node temp;
				memset(temp.nxt, 0, sizeof(temp.nxt));
				v.push_back(temp);
				int lst = v.size() - 1;
				v[i].nxt[num] = lst;
				i = lst;
			}
			else i = v[i].nxt[num];
		}
		v[i].s2.push_back(s2);
	}
}t;

int n, q;

int main(){
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	t.init();
	scanf("%d%d", &n, &q);
	string s1, s2, t1, t2;
	for (int i = 1; i <= n; ++i) {
		cin >> s1 >> s2;
		t.add(s1, s2);
	}
	while (q--) {
		cin >> t1 >> t2;
		int l = t1.length(), mst = l - 1, ans = 0; // max same tail
		while (mst >= 0 and t1[mst] == t2[mst]) --mst;
		for (int i = 0; i <= mst and (i == 0 or t1[i-1] == t2[i-1]); ++i) {
			int t1i = i, ti = 0;
			while (t1i <= mst) {
				int num = t1[t1i] - 'a' + 1;
				//printf("i: %d, t1i: %d, char: %c, nxt: %d\n", i, t1i, t1[t1i], t.v[ti].nxt[num]);
				if (t.v[ti].nxt[num] == 0) goto flag1;
				++t1i, ti = t.v[ti].nxt[num];
			}
			while (t1i <= l) {
				for (string r: t.v[ti].s2) {
					ans += r == t2.substr(i, t1i);
					//printf("i: %d, t1i: %d, char: %c\n", i, t1i, t1[t1i]);
					cout << r << ' ' << t2.substr(i, t1i) << endl;
					if (r == t2.substr(i, t1i)) {
						//printf("i: %d, t1i: %d, ++ans\n", i, t1i);
						cout << r << endl;	
					}
					
				}
				int num = t1[t1i] - 'a' + 1;
				if (t.v[ti].nxt[num] == 0) goto flag1;
				++t1i, ti = t.v[ti].nxt[num];
			}
			flag1:;
			//printf("i: %d, ans: %d\n", i, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}

