#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long digits[10];
	cin>>s;
	for(int i=0;i<10;i++)
		digits[i]=0;
	for(int i=0;i<s.length();i++)
		if(isdigit(s[i]))
			digits[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(long long j=0;j<digits[i];j++)
			cout<<i;
	return 0;
}
