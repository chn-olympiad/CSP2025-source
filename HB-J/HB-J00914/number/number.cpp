#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
long long c[105];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			c[s[i]-'0']++;
		}
	}
	sort(a,a+l,cmp);
	for(long long  i=0;i<l;i++)
	{
		if(c[a[i]]>0)
		{
			
			cout<<a[i];
			c[a[i]]--;
		}
		else
		{
			
			continue;
		}
	}
	return 0;
}
