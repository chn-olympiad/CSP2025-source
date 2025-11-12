#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;

bool cmp(int a,int b) {
	return a>b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(char ch : s) {
		if('0' <= ch && ch <= '9') ans.push_back(ch-'0');
	}
	
	sort(ans.begin(),ans.end(),cmp);
	
	for(auto it : ans) {
		cout<<it;
	}
	return 0;
}