#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string a[500005], b[500005], c, d; int n, q, sum;
string replace(string t, string h, string j,int l){
	string pp = "";
	if (l + (int)h.length() > (int)t.length()) return "false";
	for (int i = l; i < l + (int)h.length(); i++) pp += t[i];
	if (pp != j) return "false";
	string hh = "", hhh = "";
	for (int i = 0; i < l; i++) hh += t[i];
	for (int i = l + (int)h.length() - 1; i < (int)t.length(); i++) hhh += t[i];
	return hh + h + hhh;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for (int i = 1; i <= q; i++){
		sum = 0;
		cin >> c >> d;
		for (int j = 0; j < (int)c.length(); j++){
			for (int k = 1; k <= n; k++){
				string jy = replace(c, b[i], a[i], j);
				if (jy == d) sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
