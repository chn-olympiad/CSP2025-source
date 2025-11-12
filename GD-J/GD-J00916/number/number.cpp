#include <bits/stdc++.h>
using namespace std ;
string s ;
long long n[1000010],cnt ;
bool cmp (int x,int y) {
	return x>y ;
}
int main () {
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	cin >> s ;
	for (int i=0;i<s.size();i++) {
		if (s[i]>='0' && s[i]<='9') {
			n[i]=s[i]-'0' ;
			cnt++ ;
		}
	}
	sort(n,n+s.size(),cmp) ;
	for (int i=0;i<cnt;i++) {
		cout << n[i] ;
	}
}
