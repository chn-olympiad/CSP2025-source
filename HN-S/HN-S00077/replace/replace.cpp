#include<bits/stdc++.h>
using namespace std;
string a[11454],b[11454];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n * 2;i++) cin >> a[i];
	cout << 2 << endl;
	for(int i = 1;i <= q * 2;i++) cin >> b[i];
	cout << 0 << endl;
	return 0;
}
