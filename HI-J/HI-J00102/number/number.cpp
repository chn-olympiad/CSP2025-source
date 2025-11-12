#include"bits/stdc++.h"
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s2;
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++)
		if(isdigit(s[i]))
		s2=s2+s[i];
	len=s2.size();
	for(long long i=0;i<len;i++)
	{
		for(long long j=i+1;j<len;j++)
			if(s2[i]<s2[j]) swap(s2[i],s2[j]);
	}
	cout<<s2;
	return 0;
 } 
