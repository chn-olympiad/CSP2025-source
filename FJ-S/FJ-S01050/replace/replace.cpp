#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll l1 = 131, m1 = 503192685832909, l2 = 151, m2 = 110294182508684;

template<typename T>
void read(T& x) {
	x = 0;
	char c;
	while(!isdigit(c = getchar()));
	do
		x = x * 10 + (c ^ 48);
	while(isdigit(c = getchar()));
}

int reads(char *x) {
	char *g = x;
	while(!isalpha(*x = getchar()));
	do
		x ++;
	while(isalpha(*x = getchar()));
	return x - g;
}

int N, Q;
char t1[5000006], t2[5000006];
char A[5000006], B[5000006], *as[5000006], *bs[5000006], C[5000006], D[5000006];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(N), read(Q);
	as[0] = A + 1, bs[0] = B + 1;
	for(int i = 1; i <= N; i ++) {
		as[i] = as[i - 1] + reads(as[i - 1]);
		bs[i] = bs[i - 1] + reads(bs[i - 1]);
	}
	while(Q --) {
		int len = reads(C);
		reads(D);
		if(strlen(C) != strlen(D)) {
			printf("0\n");
			return 0;
		}
		int lpt = 0, rpt = len - 1;
		while(C[lpt] == D[lpt])
			lpt ++;
		while(C[rpt] == D[rpt])
			rpt --;
		int qnas = 0;
		for(int i = 0; i < N; i ++) {
			int L = as[i + 1] - as[i];
			for(int j = 0; j <= lpt && j < len; j ++) {
				if(j + L - 1 < rpt)
					continue;
				//compare
				bool isy = 1;
				for(int k = j; k < j + L; k ++) {
					if(C[k] == as[i][k-j] && D[k] == bs[i][k-j])
						continue;
					isy = 0;
				}
				if(isy) {
					qnas ++;
					break;
				}
			}
		}
		printf("%d\n", qnas);
	}
	return 0;
}
