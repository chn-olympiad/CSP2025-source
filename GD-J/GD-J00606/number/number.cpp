#include<bits/stdc++.h>

using namespace std;

string s,ss;
int len;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if(isdigit(s[i])) ss+=s[i];
	sort(ss.begin(),ss.end(),greater<int>());
	cout<<ss;
	return 0;
}
