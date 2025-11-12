#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,k[200005],cnt=0;
	string s,m;
	for (int i=1;i<=n;i++) {
		cin >> s;
		for (auto x:s) {
			k[x]++;
			cnt++;
		}
	}
	for (int i=1;i<=q;i++) {
		cin >> m;
		for (auto x:m) {
			k[x]++;
			cnt++;
		}
		cout << cnt << endl;
		cnt=0;
	}
	
	return 0;
}
