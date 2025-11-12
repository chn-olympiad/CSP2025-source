#include <bits/stdc++.h>
using namespace std;

int a[15],flag=0;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-48]++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			cout<<i;
			if (flag==0&&i==0)
			{
				break;
			}
			if (flag==0&&i!=0)
			{
				flag=1;
			}
			a[i]--;
		}
	} 
	return 0;
 } 