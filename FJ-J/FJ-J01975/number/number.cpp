#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int s,b[10],x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(a[s]!='\0')
	{
		s++;
	}
	for(int i=0;i<s;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			x = a[i];
			b[x-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(b[i]!=0)
		{
			for(int j=1;j<=b[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
 } 
 
