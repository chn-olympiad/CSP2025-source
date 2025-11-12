#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	int n,c=0,d;
	char a[1000000]={};
	gets(a);
	n=strlen(a);
	char b[n];
	for(int i=0;i<=n-1;i++)
	{
		if((a[i]<='9')&&(a[i]>='0'))
		{
			b[c]=a[i];
			c++;
		}
	}
	d=strlen(b);
	char e[d];
	for(int i=0;i<=d-1;i++)
	{
		e[i]=b[i];
	}
	sort(e,e+d);
	for(int i=d-1;i>=0;i--)
	{
		cout<<e[i];
	}
	return 0;
}
