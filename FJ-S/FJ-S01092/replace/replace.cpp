#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;

const int N = 200010, M = 5000010;
int n, q;	
string s[N][3]; 
string t[N][3];

//namespace Subtask2 {
//	bool check() {
//		for (int i = 1; i <= n; i ++) 
//			for (int j = 1; j <= 2; j ++) {
//				string S = s[i][j]; 
//				int cntb = 0;
//				for (int k = 0; k < S.size(); k ++)
//					if (S[k] != 'a' && S[k] != 'b') return false;
//					else if (S[k] == 'b') cntb ++;
//				if (cntb != 1) return false;
//			}
//		for (int i = 1; i <= q; i ++) 
//			for (int j = 1; j <= 2; j ++) {
//				string S = t[i][j]; 
//				int cntb = 0;
//				for (int k = 0; k < S.size(); k ++)
//					if (S[k] != 'a' && S[k] != 'b') return false;
//					else if (S[k] == 'b') cntb ++;
//				if (cntb != 1) return false;
//			}
//		return true;
//	}
//	vector<int> cnt[M << 1];
//	void main() {
//		
//	}
//}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; i ++) cin >> t[i][1] >> t[i][2];
//	if (Subtask2::check()) {
//		Subtask2::main();
//		return 0;
//	}
	for (int T = 1; T <= q; T ++) {
		string t1 = t[T][1], t2 = t[T][2];
		int m = t1.size(); 
		int st = -1, ed = m; 
		for (int i = 0; i < m; i ++)	
			if (t1[i] != t2[i]) { st = i; break; }
		for (int i = m - 1; i >= 0; i --)
			if (t1[i] != t2[i]) { ed = i; break; }
		LL ans = 0;
		for (int i = 1; i <= n; i ++) {
			int len = s[i][1].size();
			string s1 = s[i][1], s2 = s[i][2];
			for (int j = 0; j < len; j ++) {
				if (j <= st && s1[j] == t1[st] && s2[j] == t2[st]) {
					int to = len - j - 1;
					if (st + to < ed || st + to >= m) continue;
					if (s1 == t1.substr(st - j, len) && s2 == t2.substr(st - j, len)) 
						ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

