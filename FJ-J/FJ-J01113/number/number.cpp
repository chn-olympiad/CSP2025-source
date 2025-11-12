#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>ans;
bool cmp(int A,int B) {
	return A>B;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			ans.push_back(s[i]-'0');
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(unsigned i=0;i<ans.size();i++) {
		cout<<ans[i];
	}
	return 0;
}
