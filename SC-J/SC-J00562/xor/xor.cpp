// long long first!!!!!!!!
//n 5 * 10^5, k 10^20;
//dp
#include <bits/stdc++.h>
using namespace std;

struct lr {
	int l, r;
	lr(int _l, int _r) {
		l = _l;
		r = _r;
	}
};
bool cmp(lr a, lr b) {
	if (a.l != b.l) {
		return a.l < b.l;
	}
	return a.r < b.r;
}
long long k, r[500001];
int f[500001][2];
int n;
int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	//什么鬼 
	cin >> n >> k;
	vector <lr> o;

	for(int i = 0; i < n; i ++) {
		cin >> r[i];
	}
	//cout << "?";
	for(int i = 0; i < n; i ++) {
		if(r[i] == 0) {
			continue;
		}
		long long xore = 0;
		for (int j = i; j < n; j ++) {
			if(r[j] == 0) {
				continue;
			}
			xore = xore ^ r[j];
			if (xore == k) {
				o.push_back(lr(i, j));
				//cout << i << " wow " << j << endl;
				break;
			}
		}
	}
	//cout << "now!" << endl;
	sort(o.begin(), o.end(), cmp);
	
	f[0][0] = 0;
	f[0][1] = 1;
	for (int i = 1; i < o.size(); i++) {
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		if(o[i - 1].r < o[i].l) {
			//cout << "no problem" << endl;
			f[i][1] = max(f[i - 1][1] + 1, f[i - 1][0] + 1);
		}else {
			//cout << "boom!" << o[i - 1].r << " " << o[i].l << endl;
			f[i][1] = f[i - 1][0] + 1;
		}
		//cout << "i: " << i << " f[i][0]:" << f[i][0] << " f[i][1]:" << f[i][1] << endl;
	}
	cout << max(max(f[o.size() - 1][0], f[o.size() - 1][1]), 0);
	return 0;
}

//????????????????????????????????????????????














//???????????????????????????????????????????????????????????????
//struct tree {
//	long long k;
//	int l, r;
//	tree *le = nullptr;
//	tree *ri = nullptr;
//};
//	tree node;
//	node.l = 0;
//	node.r = n - 1;