#include<bits/stdc++.h>
using namespace std;
int a[15]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[10005];
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i])
		for(int j=1;j<=a[i];j++)
		{
			printf("%d",i);
		 } 
	}
	return 0;
} 
