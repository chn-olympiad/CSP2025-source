#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#define N (int)(2e5 + 10)
#define msg(Args...) fprintf(stderr, Args)
//#define LOCAL

using namespace std;

string s1[N], s2[N];

int main() {
	#ifndef LOCAL
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
	#endif
	
	ios :: sync_with_stdio(false);
	cin.tie(nullptr); 
	
	int n, q;
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	
	while (q--) {
		int ans = 0;
		
		string t1, t2;
		cin >> t1 >> t2;
		
		for (int i = 1; i <= n; i++) {
			size_t nxt = t1.find(s1[i]);
			while (nxt != string :: npos) {
				string tmp = t1;
				tmp.replace(nxt, s1[i].length(), s2[i]);
				ans += tmp == t2; 
				nxt = t1.find(s1[i], nxt + 1);
			}
		}
		
		cout << ans << '\n';
	}
	
	cout.flush();
	
	#ifndef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	
	return 0;
}
