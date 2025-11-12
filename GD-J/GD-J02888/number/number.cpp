#include<bits/stdc++.h>
using namespace std;
vector<int> a;
string s;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0; i<s.size(); i++) if(s[i]>='0'&&s[i]<='9') a.push_back(s[i]-'0');
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0) cout<<0;
	else
		for(auto c:a) cout<<c;

	return 0;
}
