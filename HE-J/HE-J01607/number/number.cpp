#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int c=0;
	int l=strlen(s+1);
	for(int i=1;i<=l;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[++c]=s[i]-'0';
		}
	}	
	sort(a+1,a+c+1);
	if(a[c]==0)
	{
		printf("0");
		return 0;
	}
	for(int i=c;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
