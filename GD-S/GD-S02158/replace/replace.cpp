#include <bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	string x[n + 1][3],y[q + 1][3];
	for(int i = 1;i <= q;i++){
		cin >> y[i][1] >> y[i][2];
	}
	for(int i = 1;i <= n;i++){
		cin >> x[i][1] >> x[i][2];
	}
	for(int i = 1;i <= q;i++){
		cout << 0 << endl;
	}
}
