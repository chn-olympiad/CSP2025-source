#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0; i<s.length(); i++) {
		if(0<=s[i]-'0'&&s[i]-'0'<=9)a[s[i]-'0']++;
	}
	for(int i=9; i>=0; i--) {
		if(a[i]) {
			for(int j=a[i]; j>=1; j--)
				cout<<i;
		}
	}
	return 0;
}
