#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int lens,lena=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	lens=strlen(s+1);
	for(int i=1;i<=lens;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[lena]=s[i]-'0';
			lena++;
		}
	}
	sort(a+1,a+lena);
	for(int i=lena-1;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
} 
