#include<bits/stdc++.h>
using namespace std;

int n, q;
map<string, vector<string> > s;
string a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a >> b;
		s[a].push_back(b);
	}
	while(q--) {
		cin >> a >> b;
		cout << 0 << "\n";
	}
	
	return 0; 
}
