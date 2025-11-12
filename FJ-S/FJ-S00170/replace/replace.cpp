#include <bits/stdc++.h>
using namespace std;
long long n, q, l;
string t1, t2, s1[200005], s2[200005];
int main(){
	freopen("replace.in", "w", stdin);
	freopen("replace.out", "r", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++){
		cin >> t1 >> t2;
		long long a = 0, v1 = 0, v2 = 0, v3 = 0, v4 = 0, sum = 0;
		string g1, g2, g3, g4;
		for (int i = 0; i < t1.size(); i++){
			if (t1[i] != t2[i]){
				if (v1 == 0) v1 = i;
				g1 += g3;
				g2 += g4;
				g1 += t1[i];
				g2 += t2[i];
				g3 = "";
				g4 = "";
			}
			if ((t1[i] == t2[i]) && (v1 != 0)){
				g3 += t1[i];
				g4 += t2[i];
			}
		}
		a = g1.size();
		for (int j = 1; j <= n; j++){
			v4 = 0;
			for (int k = 0; k <= s1[j].size()-a; k++){
				v2 = 0;
				long long l = k, r = k+a-1;
				for (int m = l; m <= r; m++){
					if ((s1[j][m+v1] != g1[m]) || (s2[j][m+v1] != g2[m])){
						v2 = 1;
						break;
					}
				}
				if (!v2){
					v2 = k+1;
					v4 = 1;
					break;
				}
			}
			if (v4){
				long long v = v1 - v2;
				if (v >= 0){
					for (int k = v; k <= v+a-1; k++){
						if ((s1[j][k-v] != t1[k]) || (s2[j][k-v] != t2[k])){
							v3 = 1;
							break;
						}
					}
					if (!v3) sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
