#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int L = 2005;
const int P = 13331;

int n, q;
char str1[N][L], str2[N][L];
int Len[N];
unsigned long long ha1[N];
unsigned long long ha2[N];
unsigned long long p[N];
unsigned long long haa[L];
unsigned long long hab[L];
int l1[N], r1[N];
char s1[L], s2[L];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	p[0] = 1;
	for (int i = 1; i <= 2000; ++i) {
		p[i] = p[i-1] * 13331;
	}
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s%s", str1[i], str2[i]);
		int l, r;
		int len = strlen(str1[i]);
		for (l = 0; l < len; ++l) {
			if (str1[i][l] != str2[i][l])
				break;
		}
		for (r = len-1; r >= 0; --r) {
			if (str1[i][r] != str2[i][r])
				break;
		}
		ha1[i] = 0;
		ha2[i] = 0;
		for (int j = 0; j < len; ++j) {
			ha1[i] = ha1[i]*P+str1[i][j];
			ha2[i] = ha2[i]*P+str2[i][j];
		}
		l1[i] = l, r1[i] = r;
		Len[i] = len;
	}
	while (q--) {
		scanf("%s%s", s1, s2);
		int l, r;
		int len = strlen(s1);
		for (l = 0; l < len; ++l) {
			if (s1[l] != s2[l])
				break;
		}
		for (r = len-1; r >= 0; --r) {
			if (s1[r] != s2[r])
				break;
		}
		int ans = 0;
		haa[0] = 0;
		hab[0] = 0;
		for (int i = 1; i <= len; ++i) {
			haa[i] = haa[i-1] * P + s1[i-1];
			hab[i] = hab[i-1] * P + s2[i-1];
		}
		for (int i = 1; i <= n; ++i) {
			if (r1[i]-l1[i] != r-l) {
				continue;
			} else {
				int s = l - l1[i];
				int t = s+Len[i]-1;
			//	cout << s << " " << t << endl;
				if (s<0||t>=len)
					continue;
				++s, ++t;
			//	cout << ha1[i] << " " << ha2[i] << endl;
		//		cout << haa[t]-haa[s-1]*p[t-s+1] << " " <<
			//		hab[t]-hab[s-1]*p[t-s+1] <<endl;
				if (ha1[i]==haa[t]-haa[s-1]*p[t-s+1] && ha2[i] == hab[t]-hab[s-1]*p[t-s+1]) {
					++ans;
				}
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i <= len; ++i) {
			haa[i] = 0;
			hab[i] = 0;
		}
	}

	return 0;
}
