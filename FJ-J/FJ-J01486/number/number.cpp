#include<bits/stdc++.h>
using namespace std;
int a[10005],j=0,n=0;
int main()
{
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			a[j]=s[i];
			j++;
		}
	}
	for (int i=0;i<j;i++)
	{
		for (int k=0;k<j-i;k++)
		{
			if (a[k]<a[k+1])
			{
				n=a[k];
				a[k]=a[k+1];
				a[k+1]=n;
				n=0;
			}
		}
		
	}
	for (int i=0;i<j;i++)
	{
		cout<<a[i]-48;
	}
	return 0;
}
