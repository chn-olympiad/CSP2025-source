#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector <int> num;
	for(long long i=0; i<s.length(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			num.push_back(int(s[i]-'0'));
		}
	}
	sort(num.begin(),num.end(),greater<int>());
	for(int i:num) {
		cout<<i;
	}
	return 0;
}
