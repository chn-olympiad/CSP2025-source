#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int b[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0; i<=s.length(); i++)
		if(s[i]>=48&&s[i]<=57)
			b[s[i]-'0']++;
	for(int i=9; i>=0; i--)
		if(b[i])
			for(int t=1; t<=b[i]; t++) cout<<i;
	return 0;
}
