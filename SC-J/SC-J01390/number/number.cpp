#include <bits/stdc++.h>

using namespace std;

string s, ans;
long long tong0, tong1, tong2, tong3, tong4, tong5, tong6, tong7, tong8, tong9;
int main() {
	freopen ("number.in", "r",stdin);
	freopen ("number.out", "w",stdout);
	cin >> ans;
	long long len = ans.size();
//	cout << len << endl;
	if (len == 1) {
		cout << ans << endl; 
		return 0;
	}
//	cout << ans << endl;
	for (int i = 0; i < len; i++) {
		if (ans[i] >= '0' && ans[i] <= '9') {
			if (ans[i] == '0') tong0++;
			else if (ans[i] == '1') tong1++;
			else if (ans[i] == '2') tong2++;
			else if (ans[i] == '3') tong3++;
			else if (ans[i] == '4') tong4++;
			else if (ans[i] == '5') tong5++;
			else if (ans[i] == '6') tong6++;
			else if (ans[i] == '7') tong7++;
			else if (ans[i] == '8') tong8++;
			else if (ans[i] == '9') tong9++;
		}
	}
//	cout << tong1 << " " << tong2 << " " << tong3 << " " << tong4 << " " << tong5 << " " << tong6 << " " << tong7 << " " << tong8 << " " << tong9 << " " << tong0 << endl; 
	if (tong1 == 0 && tong2 == 0 && tong3 == 0 && tong4 == 0 && tong5 == 0 && 
	tong6 == 0 && tong7 == 0 && tong8 == 0 && tong9 == 0) {
		cout << "0";
		return 0;
	}
	if (tong9 != 0) {
		for (long long i = 1; i <= tong9; i++) {
			cout << '9';
		}
	} 
	if (tong8 != 0) {
		for (long long i = 1; i <= tong8; i++) {
			cout << '8';
		}
	}
	if (tong7 !=0) {
		for (long long i = 1; i <= tong7; i++) {
			cout << '7';
		}
	}
	if (tong6 !=0) {
		for (long long i = 1; i <= tong6; i++) {
			cout << '6';
		}
	}
	if (tong5 !=0) {
		for (long long i = 1; i <= tong5; i++) {
			cout << '5';
		}
	}
	if (tong4 !=0) {
		for (long long i = 1; i <= tong4; i++) {
			cout << '4';
		}
	}
	if (tong3 !=0) {
		for (long long i = 1; i <= tong3; i++) {
			cout << '3';
		}
	}
	if (tong2 !=0) {
		for (long long i = 1; i <= tong2; i++) {
			cout << '2';
		}
	}
	if (tong1 !=0) {
		for (long long i = 1; i <= tong1; i++) {
			cout << '1';
		}
	}
	if (tong0 !=0) {
		for (long long i = 1; i <= tong0; i++) {
			cout << '0';
		}
	}
	return 0;
}