#include <bits/stdc++.h>
using namespace std;
long long a[9];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b;
	cin>>b;
	for (int i=0;i<b.size();i++)
	{
		if (b[i]>='0'&&b[i]<='9')
		{
			a[b[i]-48]++;
		}
	}
	bool c=false;
	for (int i=9;i>=1;i--)
	{
		if (a[i]!=0)
		{
			c=true;
			break;
		} 
	}
	if (c)
	{
		for (int i=9;i>=0;i--)
		{
			while (a[i]>0)
			{
				cout<<i;
				a[i]--;
			}
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
