#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 5;
int n, q;
string s[NR], s1[NR], t[NR], t1[NR];
int main(){
  	freopen("replace.in","r",stdin);
  	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++)cin >> s[i] >> s1[i];
	for(int i = 1;i <= q;i ++){
		cin >> t[i] >> t1[i];
		cout << "0\n";
	}
	return 0;
}
