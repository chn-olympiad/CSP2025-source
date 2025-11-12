#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b="";
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if (a[i]>='0'&&a[i]<='9')
		{
			b+=a[i];
		}
	}
	for(int j=0;j<b.length();j++)
	{
		for(int i=b.length();i>0;i--)
		{
			if (b[i]>b[i-1])
			{
				swap(b[i],b[i-1]);
			}
		}
	}
	cout<<b;
	return 0;
}
