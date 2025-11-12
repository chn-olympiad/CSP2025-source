#include<bits/stdc++.h>
using namespace std;
long long num[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	s1="";
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;i++)
		if('0'<=s[i]&&s[i]<='9') num[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		if(num[i]!=0)
			for(int j=1;j<=num[i];j++)s1+=(i+48);
	cout<<s1;
	return 0; 
} 