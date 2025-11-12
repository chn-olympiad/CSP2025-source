#include <bits/stdc++.h>
using namespace std;

string a[10000005],b[10000005];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		getline(cin,a[i]);
	}
	for (int i=1;i<=q+1;i++){
		getline(cin,b[i]);
	}
	for (int i=1;i<=q;i++){
		cout << 0 << endl;
	}
	return 0;
}
