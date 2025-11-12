#include <bits/stdc++.h>
#define N 200005
//#define int long long
using namespace std;
inline int read(){
	int res = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (f > 0 ? res : -res);
} 
struct node {
	string s1, s2;
}d[N];
string S(string s, int l, int r){
	string t = "";
	for (int i = l; i <= r; i++) t += s[i];
	return t;
}
int main(){
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout); 
	int n = read(), q = read();
	
	for (int i = 1; i <= n; i++){
		cin >> d[i].s1 >> d[i].s2;
	}
	while(q--){
		bool f = 1;
		string t1, t2;
		cin >> t1 >> t2;
		
		int cnt = 0;
		int pos1 = 0, pos2 = 0;
		for (int i = 0; i <= t1.length(); i++){
			if (t1[i] != 'a' || t1[i] != 'b') {
				f = 0;
				break;
			}
			if (t1[i] == 'b') {
				cnt++;
				if (cnt > 1) {
					f = 0;
					break;
				}
				else pos1 = i;
			}
		}
		cnt = 0;
		if (f) for (int i = 0; i <= t2.length(); i++){
			if (t2[i] != 'a' || t2[i] != 'b') {
				f = 0;
				break;
			}
			if (t2[i] == 'b') {
				cnt++;
				if (cnt > 1) {
					f = 0;
					break;
				}
				else pos2 = i;
			}
		}
		
		int ans = 0;
		int len = t1.length();
		for (int i = 1; i <= n; i++){
//			cout << i << ":  "; 
//			cout << d[i].s1.length() << "\n";
			if (d[i].s1.length() > len) continue;
			for (int j = 0; j <= len - d[i].s1.length(); j++){
				if (d[i].s1[0] == t1[j]) {
//					cout << j << " ";
					bool f = 1;
					for (int id = 0; id < d[i].s1.length(); id++){
						if (d[i].s1[id] != t1[id + j]) {
							f = 0;
							break;
						}
					}
//					if (f) puts("true");
					if (!f) continue;
					string ss = S(t1, 0, j - 1), sss = S(t1, j + d[i].s1.length(), len - 1);
//					cout << ss << " " << d[i].s2 << " " << sss << "\n";
					string t11 = ss + d[i].s2 + sss;
					if (t11 == t2){
						ans++;
					}
				}
//				cout << "ndffsdfdfsdffnf" << ans << "\n";
			}
//			cout << "ndsdsafnf" << ans << "\n";
		}
//		cout << "nfnf ";
		cout << ans << "\n";
	}
	
	return 0;
}
