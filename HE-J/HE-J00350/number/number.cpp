#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b[100010],fl=0;
	long long ci=0;
	string a;
	cin>>a;
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]=='0')
		{
			b[ci]=a[i]-'0';
			ci++;
		}
		if(a[i]=='1')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='2')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='3')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='4')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='5')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='6')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='7')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='8')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
		if(a[i]=='9')
		{
			b[ci]=a[i]-'0';
			fl=1;
			ci++;
		}
	}
	sort(b,b+ci);
	if(!fl)
	{
		cout<<"0";
		return 0;
	}
	for(long long i=ci-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
