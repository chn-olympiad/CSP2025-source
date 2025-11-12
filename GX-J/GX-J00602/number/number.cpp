#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int c[1000010];
	int h=0,m=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			c[m]=s[i]-48;
			m++;
			h++;
		}
	}
	sort(c,c+h);
	for(int i=h-1;i>=0;i--)
	{
		cout<<c[i];
	}
	return 0;
}
