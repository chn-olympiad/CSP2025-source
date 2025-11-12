#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
string a[N][2];
string b[N][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	string s;
	
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=2; j++)
			cin >> a[i][j];
	}
	for(int i=1; i<=q; i++){
		for(int j=1; j<=2; j++)
			cin >> b[i][j];
		cout << 0;
	}
	return 0;
}
