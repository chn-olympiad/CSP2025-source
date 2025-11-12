#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXLEN = 5000005;

struct PAIR {
	vector<char> fro, mid, bac;
	
	void OUT() {
		cout << fro.size() << " ";
		for (int i = 0; i < (int) fro.size(); ++i) cout << fro[i];
		cout << mid.size() << " ";
		for (int i = 0; i < (int) mid.size(); ++i) cout << mid[i];
		cout << bac.size() << " ";
		for (int i = 0; i < (int) bac.size(); ++i) cout << bac[i];
		cout << endl;
	}
};

int n, q;
char in_x[MAXLEN], in_y[MAXLEN];
PAIR s[MAXN];

void CHANGE(char x[], char y[], PAIR& t) {
	int len = strlen(x);
	
	int l = 0, r = len - 1;
	for (; l < len && x[l] == y[l]; ++l) t.fro.push_back(x[l]);
	for (; r > l && x[r] == y[r]; --r) t.bac.push_back(x[r]);
	for (int i = l; i <= r; ++i) {
		t.mid.push_back(x[i]);
		t.mid.push_back(y[i]);
	}
	return;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", in_x);
		scanf("%s", in_y);
		CHANGE(in_x, in_y, s[i]);
	}
	
	PAIR t;
	while (q--) {
		t.fro.clear();
		t.mid.clear();
		t.bac.clear();
		
		scanf("%s", in_x);
		scanf("%s", in_y);
		CHANGE(in_x, in_y, t);
		
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (t.mid.size() != s[i].mid.size() ) continue;
			if ( t.fro.size() < s[i].fro.size() ) continue;
			if ( t.bac.size() < s[i].bac.size() ) continue;
			
			bool flag = 1;
			int tlen = t.mid.size();
			for (int j = 0; j < tlen; ++j) 
				if (t.mid[j] != s[i].mid[j]) {
					flag = 0;
					break;
				}
			if (!flag) continue;
			
			int len1 = t.fro.size() - 1, len2 = s[i].fro.size() - 1;
			for (; len2 >= 0; --len1, --len2)
				if ( t.fro[len1] != s[i].fro[len2] ) {
					flag = 0;
					break;
				}
			if (!flag) continue;
			
			len1 = t.bac.size() - 1, len2 = s[i].bac.size() - 1;
			for (; len2 >= 0; --len1, --len2)
				if ( t.bac[len1] != s[i].bac[len2] ) {
					flag = 0;
					break;
				}
			if (!flag) continue;
			
			++sum;
		}
		printf("%d\n", sum);
	}
}
