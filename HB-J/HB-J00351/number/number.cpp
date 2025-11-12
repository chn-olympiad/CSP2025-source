#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int zz=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long unsigned int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[zz]=s[i];
			zz++;
		}
	}
	sort(a,a+zz);
	for(int i=zz-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
