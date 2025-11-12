#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,n[11],s,m;
	cin>>a;
	while(a)
	{
		s=a%10;
		n[s]=n[s]+1;
		a=a/10;
	}
	for(int i=11;i>=0;i--)
	{
		m=n[i];
		for(int j=0;j<=m;j++)
		{
			cout<<i;
		}
	}
	return 0;
}
