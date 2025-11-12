#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[11]; string s;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	getline(cin , s);
	LL len = s.size();
	for(LL i = 0 ; i < len ; i++) if(s[i] >= '0' && s[i] <= '9') a[s[i] - '0']++;
	for(LL i = 9 ; i >= 0 ; i--) for(LL j = 1 ; j <= a[i] ; j++) cout << i;
	return 0;
}
