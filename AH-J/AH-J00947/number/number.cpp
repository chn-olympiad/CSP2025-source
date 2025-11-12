#include <bits/stdc++.h>
using namespace std;
string s;
int n[10];
int main () {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int a=s.size();
    for (int i=0;i<a;i++) {
		if (s[i]>='0'&&s[i]<='9') {
                s[i]-='0';
                n[s[i]]++;
		}
	}
	for (int i=9; i>=0; i--) {
	    for (int j=1; j<=n[i]; j++) cout << i;
	}
    return 0;
}
