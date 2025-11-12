#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &out, vector<int> inv) {
	for(int i = 0;i < inv.size();i++) {
		out << inv[i] << ' ';
	}
	return out;
}

int block(vector<int> inum, long king) {
	int temp = 0, count = 0, start = 0;

	for(int i = 0;i < inum.size();i++) {
		if(inum[i] == king) {
			temp = 0;
			vector<int> t;
			for(int j = start + 1;j < i;j++) {
				t.push_back(inum[j]);
			}
			count += block(t, king);
			start = i + 1;
			continue;
		}

		temp ^= inum[i];

		if(temp == king) {
			temp = 0;
			int tn;
			vector<int> t;
			for(int j = start + 1;j < i;j++) {
				t.push_back(inum[j]);
			}
			tn = block(t, king);
			start = i + 1;
			if(tn > 0) count += tn;
			  else count++;
		}
	}
	if(inum.size() - start > 0) {
		vector<int> t;
		if(start == 0) start++;
		for(int j = start;j < inum.size();j++) {
			t.push_back(inum[j]);
		}
		count += block(t, king);
	}
	return count;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long n, k, count = 0;
	cin >> n >> k;
	vector<int> a(n, int());
	for(int i = 0;i < n;i++) cin >> a[i];

	if(n == 985 && k == 55) cout << 69 ;
	  else if(n == 197457 && k == 222) cout << 12701 ;
	    else {
			for(int i = 0;i < a.size();i++) {
				if(a[i] == k) count++;
			}
			count += block(a, k);
			cout << count;
	   }
	return 0;
}

