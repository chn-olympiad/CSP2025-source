#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 1e5 + 10;
string a[maxn],b[maxn];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		
		cin >> a[i] >> b[i];
	}
	while (q--) {
		string t1,t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
 {
		cout << 0 << endl;
		continue;
	 }
	 int posl = 0,posr = 0;
	 		for (int i = 0; i < (int)t1.size(); i++) {
				if (t1[i] != t2[i]) {
					posl = i;
					break;
				}
		}
		for (int i= t1.size(); i >= 0; i--) {
			if (t1[i] != t2[i]) {
				posr = i;
				break;
			}
		}
		int ans = 0;
		for (int i = 0; i <= posl; i++) {
			for (int j = 1; j <= n; j++) {
				if (i + (int)a[j].size() < posr) continue;
				int t = 1;
				for (int k = 0; k < (int)a[j].size(); k++) {
					if (a[j][k] != t1[i + k]) t = 0;
					if (b[j][k] != t2[i + k]) t = 0;
				} 
				ans+=t;
			}
		}
		cout << ans << endl;
	 	}
	return 0;
}
