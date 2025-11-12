#include<bits/stdc++.h>
using namespace std;
int q[18];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string a;
	int m=0;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[m]=s[i];
			m++;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(a[i]=='0')
		{
			q[0]++;
		}
		if(a[i]=='1')
		{
			q[1]++;
		}
		if(a[i]=='2')
		{
			q[2]++;
		}
		if(a[i]=='3')
		{
			q[3]++;
		}
		if(a[i]=='4')
		{
			q[4]++;
		}
		if(a[i]=='5')
		{
			q[5]++;
		}
		if(a[i]=='6')
		{
			q[6]++;
		}
		if(a[i]=='7')
		{
			q[7]++;
		}
		if(a[i]=='8')
		{
			q[8]++;
		}
		if(a[i]=='9')
		{
			q[9]++;
		}
	}
	int c=9;
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<q[i];j++)
		{
			cout<<c;
		}
		c--;
	}
	
	return 0;
}
