#include <bits/stdc++.h>
using namespace std;
using LL=long long;
string s,ss;
int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL len=s.size();
	for(LL i=0;i<len;i++){
		if(isdigit(s[i])) ss+=s[i];
	}
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	cout<<ss;
	return 0;
}
