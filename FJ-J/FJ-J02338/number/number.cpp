#include<bits/stdc++.h>
using namespace std;
char c[1000001];
int n[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gets(c);
	int len=strlen(c);
	for(int i=0;i<len;i=i+1)
	{
		for(int j=0;j<=9;j=j+1)
		{
			if(c[i]==(j+48))
			{
				n[j]=n[j]+1;
				j=10;
			}
		}
	}
	for(int i=9;i>=0;i=i-1)
	{
		for(int j=1;j<=n[i];j=j+1)
		{
			cout<<i;
		}
	}
	return 0;
}

