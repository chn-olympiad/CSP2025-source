#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],sum;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[sum++]=s[i]-'0';
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++) cout<<a[i];
	return 0;
}
