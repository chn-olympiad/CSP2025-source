#include <bits/stdc++.h>
using namespace std;
/*
bro if u r writing bf why use ac-automaton?

Actually, it can only pass tast case 1~2.
*/

pair<string, string> P[200000];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int N, Q;cin >> N >> Q;
	
	for (int i=0;i<N;i++) cin >> P[i].first >> P[i].second;
	
	for (int i=0;i<Q;i++) {
		string X, Y;cin >> X >> Y;
		if (X.length()!=Y.length()) {
			cout << 0 << '\n';
			continue;
		}
		int ans=0;
		for (int j=0;j<N;j++) {
			if (P[j].first.length()>X.length()) continue;
			for (int p=0;p<=(int)(X.length()-P[j].first.length());p++) {
				bool valid=true;
				for (int q=0;q<(int)P[j].first.length();q++) {
					if (X[p+q]!=P[j].first[q]||Y[p+q]!=P[j].second[q]) {
						valid=false;
						break;
					}
				}
				if (!valid) continue;
				string Xv=X;
				for (int q=0;q<(int)P[j].first.length();q++) Xv[p+q]=P[j].second[q];
				if (Xv==Y) {
					ans++;
					break;
				}
				
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
