#include <bits/stdc++.h>
using namespace std;
int n,m,s[1000010];
char a[1000010];
int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]!='1') {
			f=false;
		}
	}
	for (int i=1;i<=n;i++) {
		cin>>s[i];
	}
	if (f) {
		cout<<0;
	} else {
		cout<<1;
	}
	return 0;
}
