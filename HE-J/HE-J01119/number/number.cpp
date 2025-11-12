#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<char> a;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a.push_back(s[i]);
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<a.size();i++)cout<<a[i];
	return 0;
}
