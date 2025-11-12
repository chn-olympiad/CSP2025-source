#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[s.size()]; 
	for(long long i=0;i<s.size();i++)
	{
		a[i]=10;
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+s.size());
	for(long long i=s.size()-1;i>=0;i--)
	{
		if(a[i]!=10) cout<<a[i];
	}
	return 0;
}
