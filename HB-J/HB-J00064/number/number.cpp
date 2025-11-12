#include <bits/stdc++.h>
using namespace std;
int a[1000005],ii=0;
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[ii]=s[i]-'0';
			ii++;
		}
	}
	sort(a,a+ii,cmp);
	for(int i=0;i<ii;i++)
	{
		cout<<a[i];
	}
	return 0;
}
