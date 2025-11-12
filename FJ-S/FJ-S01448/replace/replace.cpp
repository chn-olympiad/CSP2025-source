#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define endl '\n'

const int N = 1e5+5;
const int MOD = 10;

struct Dic{
	string s1,s2;
} s[N];
struct Ques{
	string q1,q2;
} ql[N];
int n,q;

void solve() { // 45·Ö 
	cin >> n >> q;
	for(int i=1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
	}
	for(int i=1; i <= q; i++) {
		cin >> ql[i].q1 >> ql[i].q2;
	}
	
	for(int g=1; g <= q; g++) {
		int ans = 0;
		for(int i=1; i <= n; i++) {
			int pos1 = ql[g].q1.find(s[i].s1);
			int pos2 = ql[g].q2.find(s[i].s2); 
			if(pos1 != string::npos && pos2 != string::npos && pos1 == pos2) {
				string lsq1 = ql[g].q1,lsq2 = ql[g].q2;
				ql[g].q1.erase(pos1,s[i].s1.length());
				ql[g].q2.erase(pos2,s[i].s2.length());
				if(ql[g].q1 == ql[g].q2) {
					ans++;
				}
				ql[g].q1 = lsq1;ql[g].q2 = lsq2;
			}
		}
		cout << ans << endl;
	}
	
	return;
}

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T=1;
//	cin >> T;

	while(T--) {
		solve();
	}
	
	return 0;
}
