#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

int n, q, c;
string s1, s2, a, t;
unordered_set<string> s;
unordered_map<string, string> m;

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i=0; i<n; i++){
		cin >> s1 >> s2;
		s.insert(s1);
		m[s1] = s2;
	}
	for (int i=0; i<q; i++){
		c = 0;
		cin >> s1 >> s2;
		int l = s1.length();
		for (int j=0; j<l; j++){
			for (int k=0; k<=l-j; k++){
				a = s1.substr(j, k);
				if (s.count(a)){
					t = s1; string s3;
					int x = m[a].length();
					s3 = t.replace(t.begin()+j, t.begin()+j+x, m[a]);
					//cout << s3 << endl;
					if (s3==s2){
						c++;
					}
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}
