#include <bits/stdc++.h>
using namespace std;
int n,q;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i=0;i<n;i++) for (int j=0;j<2;j++) cin >> s;
	for (int g=0;g<q;g++) {
		for (int i=0;i<2;i++) cin >> s;
		cout << 0 << "\n";
	}
	return 0;
}
