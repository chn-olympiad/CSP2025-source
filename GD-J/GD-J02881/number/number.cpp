#include<bits/stdc++.h> 
using namespace std;
long long a[1000000+5];
string str;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for (int i=0;i<str.size();i++)
	{
		if (str[i]>='0'&&str[i]<='9')
		{
			int o=str[i]-'0';
			a[o]++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
