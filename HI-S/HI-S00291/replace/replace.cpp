#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 10;
const ull P = 13331;
int n,q;
char chr[N],t1[N],t2[N];
ull pw[N];
ull s[N][2];
int sz[N][2];
ull sum1[N],sum2[N];
ull h(ull chr[],int l,int r) {
	return chr[r] - chr[l - 1] * pw[r - l + 1];
}
int fir[N][2];
bool ok = true;
void calc() {
	for (int i = 1; i <= q; i++) {
		cin >> (t1 + 1) >> (t2 + 1);
		int len = strlen(t1 + 1),ans = 0;
		int tmp = true;
		int f1 = 0,f2 = 0;
		for (int j = 1; j <= len ;j ++) {
			if (t1[j] != 'a' && t1[j] != 'b' || t2[j] != 'a' && t2[j] != 'b') {
				tmp = false;
			}
			if (t1[j] == 'b') {
				if (f1) {
					tmp = false;
				}
				else {
					f1 = j;
				}
			}
			if (t2[j] == 'b') {
				if (f2) {
					tmp = false;
				}
				else {
					f2 = j;
				}
			}
		}
		if (ok && tmp) {
			for (int j = 1; j <= len; j++) {
				if (t1[j] == 'b') {
					f1 = j;
				}
				if (t2[j] == 'b') {
					f2 = j;
				}
			}
			for (int j = 1; j <= n; j++) {
				if (fir[j][0] <= f1 && fir[j][1] <= f2 && f1 + sz[j][0] - fir[j][0] <= len && f2 + sz[j][1] - fir[j][1] <= len && fir[j][1] - fir[j][0] == f2 - f1) {
					ans++;
				}
			}
			cout << ans << "\n";
			continue;
		}
		for (int j = 1; j <= len; j++) {
			sum1[j] = sum1[j - 1] * P + t1[j];
			sum2[j] = sum2[j - 1] * P + t2[j];
		}
		for (int j = 1; j <= len; j++) {
			for (int k = 1; k <= n; k++) {
				if (sz[k][0] <= j) {
//					cout << "i = " << i << " j = " << j << " k = " << k << "\n";
//					cout << h(sum1,j - sz[k][0] + 1,j) << " " << s[k][0] << "\n";
//					cout << h(sum2,j - sz[k][1] + 1,j) << " " << s[k][1] << "\n";
//					cout << h(sum1,1,j - sz[k][0]) << " " << h(sum2,1,j - sz[k][1]) << "\n";
//					cout << h(sum1,j + 1,len) << " " << h(sum2,j + 1,len) << "\n";
					if (h(sum1,j - sz[k][0] + 1,j) == s[k][0] && h(sum2,j - sz[k][1] + 1,j) == s[k][1] && h(sum1,1,j - sz[k][0]) == h(sum2,1,j - sz[k][1]) && h(sum1,j + 1,len) == h(sum2,j + 1,len)) {
						ans++;
//						cout << "i = " << i << " j = " << j << " k = " << k << "\n";
					}
				}
			}
		}
		cout << ans << "\n";
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		bool tmp = true;
		pw[i] = pw[i - 1] * P;
		ull hs;
		int len;
		hs = 0;
		cin >> (chr + 1);
		len = strlen(chr + 1);
		for (int j = 1; j <= len; j++) {
			hs = hs * P + chr[j];
			if (chr[j] != 'a' && chr[j] != 'b') {
				tmp = false;
				//cout << "i = " << i << " j = " << j << " t = 1" << "\n";
			}
			if (chr[j] == 'b') {
				if (fir[i][0]) {
				//cout << "i = " << i << " j = " << j << " t = 1" << "\n";
					tmp = false;
				}
				else {
					fir[i][0] = j;
				}
			}
		}
		sz[i][0] = len;
		s[i][0] = hs;
		hs = 0;
		cin >> (chr + 1);
		len = strlen(chr + 1);
		for (int j = 1; j <= len; j++) {
			hs = hs * P + chr[j];
			if (chr[j] != 'a' && chr[j] != 'b') {
				//cout << "i = " << i << " j = " << j << "\n";
				tmp = false;
			}
			if (chr[j] == 'b') {
				if (fir[i][1]) {
				//cout << "i = " << i << " j = " << j << "\n";
					tmp = false;
				}
				else {
					fir[i][1] = j;
				}
			}
		}
		sz[i][1] = len;
		s[i][1] = hs;
		ok &= tmp;
//		if (tmp == false) {
//			cout << "i = " << i << "\n";
//		}
	}
	calc();
	return 0;
}
