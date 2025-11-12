#include <bits/stdc++.h>
using namespace std;
char s[1000001];
char a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=1000000;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[(int)s[i]]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			for(int j=1;j<=a[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
