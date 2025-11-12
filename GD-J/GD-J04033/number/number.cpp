#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[10]={};
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int temp=s[i]-'0';
			a[temp]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(long long j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
