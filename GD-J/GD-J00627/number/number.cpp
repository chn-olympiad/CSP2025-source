#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int len,a[1000005],cnt=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=cnt;i++)
	{
		printf("%d",a[i]);
	 } 
	return 0;
}
