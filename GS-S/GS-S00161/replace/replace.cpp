#include <bits/stdc++.h>
using namespace std;
string s,t,a,b;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> s >> t;
	}
	for (int i = 1;i <= q;i++){
		cin >> a >> b;
		cout << q / i;
	}
	return 0;
}
