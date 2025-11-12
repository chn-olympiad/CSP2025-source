#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
 
char c;
int b[1000005],cnt=0,dx;
string a;
int main()
{
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	cin>>a;
	dx=a.size();
	for (int i=0;i<=dx;i++)
	{
		c=a[i];
		if (c<=57 && c>=48)
		{
			cnt++;
			b[cnt]=c-48;
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		int maxn=0;
		for (int j=1;j<=cnt;j++)
		{
			maxn=max(maxn,b[j]);
		}
		for (int k=1;k<=cnt;k++)
		{
			if (b[k]==maxn)
			{
				b[k]=0;
				break;
			}
		}
		cout<<maxn;
	}	
	return 0;
}
