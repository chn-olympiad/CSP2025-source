#include <bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	int v=0;
	for(int i=9;i>=0;i--)
	{
		if(a[i]>0&&i!=0)
		{
			v=1;
			for(int j=1;j<=a[i];j++)
			{
				cout<<i;
			}
		}
		if(i==0)
		{
			if(v==1)
			{
				for(int j=1;j<=a[i];j++)
				{
					cout<<i;
				}
			}else
			{
				cout<<i;
			}
		}
	}
	return 0;
}
