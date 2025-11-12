#include<bits/stdc++.h>
using namespace std;
long long num[10];
char ch;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf(" %c",&ch)!=EOF)
	{
		if(ch>='0'&&ch<='9')
		{
			num[ch-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]>0)
		{
			printf("%d",i);
			num[i]--;
		}
	}
	return 0;
 } 
