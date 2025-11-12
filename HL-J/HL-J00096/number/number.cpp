#include <bits/stdc++.h>
using namespace std;
string s,ss;
long long a,sss[1000005];
bool cmp(long long x,long long y)
{
	if(x>y)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline (cin,s);
	
	for(int i=0;i<s.size();i++)
	{
		if('[i]'>='0')
		{
			a++;
			sss[i]=s[i];
		}
		
		if('[i]'<='9')
		{
			a++;
			sss[i]=s[i];
		}

	}
	for(int i=0;i<s.size();i++)
	{
		if('s[i]'<'0'||'s[i]'>'9')
			continue;
	}
	sort(sss,sss+a,cmp);
	for(int i=0;i<a;i++)
	{
		ss[i]=sss[i];
		cout << ss[i];
	}
	return 0;
}
