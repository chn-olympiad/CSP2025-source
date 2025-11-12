#include <bits/stdc++.h>
using namespace std;
int m[15],sum,v=1;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if((s[i]>47)&&(s[i]<58))
		{
			sum=s[i]-48;
			m[sum]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<m[i];j++)
		{
			cout<<i;
		}
	}
    return 0;
} 