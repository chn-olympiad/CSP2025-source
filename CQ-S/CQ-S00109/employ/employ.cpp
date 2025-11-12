#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int Maxn = 505;
const ll MOD = 998244353;

namespace Josh_zmf {

	int N, M, c[Maxn], p[Maxn]; string s;

	int main() {
		cin>> N>> M>> s, s = ' ' + s;
		int cnt = 0;
		for(int i=1; i<=N; i++) {
			if(s[i] == '1')	cnt++;
		}
		for(int i=1; i<=N; i++)	cin>> c[i];
		if(N == M) {
			if(cnt != N)	cout<< "0\n";
			else {
				bool flag = 0;
				for(int i=1; i<=N; i++) if(c[i] == 0)	flag = 1;
				if(flag)	cout<< "0\n";
				else {
					ll ans = 1;
					for(int i=1; i<=N; i++)	ans = ans*i %MOD;
					cout<< ans<< '\n';
				}
			}
			return 0;
		}
		if(cnt < M)	return cout<< "0\n", 0;
//		cerr<< "asdf\n";
		for(int i=1; i<=N; i++)	p[i] = i;
		int ans = 0;
		do {
			int asdf = 0;
			static bool bj[Maxn];
			for(int i=1; i<=N; i++) {
				if(s[i] == '0') {
					bj[i] = 0; continue;
				}
				int cnt = 0;
				for(int j=i-1; j; j--) {
					if(!bj[j])	cnt++;
					else	break;
				}
				if(cnt >= c[p[i]])	bj[i] = 0;
				else	bj[i] = 1, asdf++;
			}
//			printf("asdf:%d\n", asdf);
			if(asdf >= M)	ans++;
		} while(next_permutation(p+1, p+1+N));
		cout<< ans<< '\n';
		return 0;
	}

}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	Josh_zmf::main();
	return 0;
}
