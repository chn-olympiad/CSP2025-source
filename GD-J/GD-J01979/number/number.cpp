#include <bits/stdc++.h>
using namespace std;
string s;
char c;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;++i)
	{
		c=s[i];
		if(c<='9' and c>='0')
		{
			int x=c-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;--i)
	{
		for(int j=1;j<=a[i];++j)
		{
			cout<<i;
		}
	}
	cout<<"\n";
	return 0;
}
