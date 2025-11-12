#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for (long long i=0;i<=len-1;i++)
	{
		if (s[i]-'0'>=0 && s[i]-'0'<=9)
		{
			a[s[i]-'0']++;
		}
	}
	for (long long i=9;i>=0;i--)
	{
		for (long long j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
