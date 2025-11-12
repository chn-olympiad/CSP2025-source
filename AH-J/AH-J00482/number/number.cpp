#include<bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	char ch;
	while(scanf("%c",&ch)!=EOF)
	{
		if('0'<=ch && '9'>=ch)
		{
			a[ch-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--)
	{
		while(a[i]--) printf("%d",i);
	}
	printf("\n");
	
	return 0;
}
