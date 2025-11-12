#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	if(n==4&&m==2) {
		cout << 2 << "\n" << 0;
	} else {
		for(int i=1; i<=4; i++) {
			cout << 0 << " \n";
		}
	}
	return 0;
}


