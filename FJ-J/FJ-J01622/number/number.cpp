#include <bits/stdc++.h>
using namespace std;

int a[10];
string s;
bool flag=false;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0' &&s[i]<='9' ) {
			a[s[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--) {
		for(int j=0; j<a[i]; j++) {
			if(flag==false && i==0) {
				cout <<0<<endl;
				break;
			} else {
				cout <<i;
				flag=true;
			}
		}
	}
	return 0;
}
