#include<bits/stdc++.h>
using namespace std;
char k;
int a[10],b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&k)!=EOF)
	{
		if(k>='0'&&k<='9')
		{
			a[k-'0']++;
		}
		else if(k>='a'&&k<='z');
		else break;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
 } 
