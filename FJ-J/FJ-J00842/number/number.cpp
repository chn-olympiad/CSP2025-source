#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000009],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	if(a[n-1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
