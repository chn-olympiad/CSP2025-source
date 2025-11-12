#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100010]={};
	int c=0,ch=0;
	cin >> s;
	for(int i = 0;i<s.size();i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[i-ch]= s[i]-'0';
			c++;
		}
		else {
			ch++;
		}
	}
	sort(a,a+c);
	for(int j=c-1;j>=0;j--) {
		cout << a[j];
	}
	return 0;
} 
