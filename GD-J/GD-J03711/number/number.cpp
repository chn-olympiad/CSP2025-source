#include<bits/stdc++.h>
using namespace std;
int num[10],n,k=9;
char a[1000001];
int main()
{
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	scanf("%s",a);
	n=strlen(a);
	for(int i=0;i<n;i++)
	{
		if(int(a[i])>=48&&int(a[i])<=57)
		{
			num[int(a[i])-48]++;
		}
	}
	while(k>=0)
	{
		if(num[k]!=0)
		{
			cout<<k;
			num[k]--;
		}
		else
		{
			k--;
		}
	}
	return 0;
} 
