#include<bits/stdc++.h>
using namespace std;
string a;
long long s[1000001],ans;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0; i<a.size(); i++) {
		if(int(a[i])>=48 && int(a[i])<58) {
			s[i]=int(a[i]);
			ans++;
		}
	}
	sort(s,s+a.size());
	for(int i=a.size()-1; i>0; i--) {
		cout<<char(s[i]);
	}
	return 0;
}
