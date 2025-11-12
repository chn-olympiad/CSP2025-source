#include<bits/stdc++.h>
using namespace std;
long long i,cnt=0,f=0;
long long a[1000100];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for (i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	if (a[cnt]==0)
	{
		cout<<0;
		return 0;
	}
	for (i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}