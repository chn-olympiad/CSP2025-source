#include<bits/stdc++.h>
using namespace std;
const int M=1e6+50;
char a[M];
int b[M];
int c=1,d=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=M;i++)
	{
		cin>>a[i];
		d++;
		if(a[i]==' ')
		{
			break;
		}
	}
	for(int i=1;i<=d;i++)
	{
		if(a[i]=='1')
		{
			b[c]=1;
			c++;
		}
		if(a[i]=='2')
		{
			b[c]=2;
			c++;
		}
		if(a[i]=='3')
		{
			b[c]=3;
			c++;
		}
		if(a[i]=='4')
		{
			b[c]=4;
			c++;
		}
		if(a[i]=='5')
		{
			b[c]=5;
			c++;
		}
		if(a[i]=='6')
		{
			b[c]=6;
			c++;
		}
		if(a[i]=='7')
		{
			b[c]=7;
			c++;
		}
		if(a[i]=='8')
		{
			b[c]=8;
			c++;
		}
		if(a[i]=='9')
		{
			b[c]=9;
			c++;
		}
		if(a[i]=='0')
		{
			b[c]=0;
			c++;
		}
		if(a[i]==' ')
		{
			break;
		}
		d++;
	}
	sort(b+1,b+d+1);
	for(int i=1;i<=c;i++)
	{
		cout<<b[i];
	}
	return 0;
}
