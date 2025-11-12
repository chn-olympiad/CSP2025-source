#include <bits/stdc++.h>
using namespace std;
bool cmp(int c,int b)
{
	if (c>=b)
	{
		return c>b;
	}
	return b>c;
}
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char s[1000005];
	for (long long i=1;i<=1000005;i++)
	{
		cin>>s[i];
	}
	int sum=0;
	for (long long i=1;i<=1000005;i++)
	{
		if (s[i]<="9"&&s[i]>="0")
		{
			sum++;
		}
	}
	long long a[1000005],k=1;
	for (int i=1;i<=sum;i++)
	{
		if (s[i]=="0")
		{
			a[k++]=0;
		}
		if (s[i]=="1")
		{
			a[k++]=1;
		}
		if (s[i]=="2")
		{
			a[k++]=2;
		}
		if (s[i]=="3")
		{
			a[k++]=3;
		}
		if (s[i]=="4")
		{
			a[k++]=4;
		}
		if (s[i]=="5")
		{
			a[k++]=5;
		}
		if (s[i]=="6")
		{
			a[k++]=6;
		}
		if (s[i]=="7")
		{
			a[k++]=7;
		}
		if (s[i]=="8")
		{
			a[k++]=8;
		}
		if (s[i]=="9")
		{
			a[k++]=9;
		}
	}
	sort(a+1,a+sum+1,cmp);
	for (int i=1;i<=sum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
