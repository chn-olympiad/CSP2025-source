#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n,a[N],ct;
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin >> s;
	s = ' ' + s;
	n = s.length();
	for(int i = 1;i < n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++ct] = s[i] - '0';
		}
	} 
	sort(a + 1,a + 1 + ct);
	while(ct){
		cout << a[ct--];
	}
	cout << '\n';
	return 0;
}
