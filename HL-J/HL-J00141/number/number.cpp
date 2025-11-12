#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,k[N];
int main() {

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	getline(cin,s);
	string x = "";
	if(s.size()==1) {
		cout<<s;
		return 0;
	}
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='a'&&s[i]<='z') {
			s[i]-=s[i];
		} else {
			n++;
			k[i]+=s[i];
		}
	}
	sort(k,k+n+1);
	reverse(k,k+n+1);
	for(int i=0; i<n; i++) {
		x+=k[i];
	}
	for(int i=0; i<n; i++) {
		cout<<x[i];
	}


	return 0;
}
