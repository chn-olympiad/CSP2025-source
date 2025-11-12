#include<bits/stdc++.h>
using namespace std;
char str[1000001];
int d[1001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++)
	d[(int)str[i]]++;
	bool p=0;
	for(int i='9';i>='0';i--)
	{
		if(i!='0')
		{
			for(int j=1;j<=d[i];j++)
			putchar(i);
			p|=d[i];
		}
		else
		{
			if(p)
			for(int j=1;j<=d[i];j++)
			putchar(i);
			else
			putchar('0');
		}
	}
}
