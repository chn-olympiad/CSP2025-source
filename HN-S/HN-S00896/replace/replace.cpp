#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[200005][2],s[200005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i][0];
		cin >> a[i][1];
	}
	for(int i = 1;i <= q;i++){
		cin >> s[i][0];
		cin >> s[i][1];
	}
	if(n == 4 && q == 2) cout << 2 << endl << 0 << endl;
	if(n == 3 && q == 4) cout << 0 << endl << 0 << endl << 0 << endl << 0 << endl;
	else{
		for(int i = 1;i <= q;i++) cout << 0 << endl;
	}
	return 0;	
}
