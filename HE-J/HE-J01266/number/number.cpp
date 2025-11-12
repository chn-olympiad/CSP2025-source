#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long s[a.length()],num=0;
	for(long i=0;i<a.length();i++)
	{
		if(a[i]<=96)
		{
			s[num]=(a[i]-'0');
			num++;
		}
	}
	sort(s,s+num);
	for(long i=num-1;i>=0;i--)
	{
		cout<<s[i];
	}
	return 0;
}
