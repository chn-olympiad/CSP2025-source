#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int c=0;
	for (int i=0; i<s.size(); i++) {
		if (s[i]-'0'<11) {
			a[i]=s[i]-'0';
			c+=1;
		}
	}
	sort(a,a+s.size());
	if (c==s.size()) {
		for (int i=c-1; i>=0; i--) {
			cout << a[i];
		}
		return 0;
	}
	for (int i=s.size()-1; i>=s.size()-c; i--) {
		cout << a[i];
	}
	return 0;
}
