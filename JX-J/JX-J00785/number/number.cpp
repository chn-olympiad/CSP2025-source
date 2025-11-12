#include<bits/stdc++.h>
using namespace std;
	char a[1000000];
	int s[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=sizeof(a);
	for(int i=0;i<n;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			s[int(a[i])]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int ii=0;ii<s[i];ii++)
		{
			cout<<i;
		}
	}
	return 0;
}
