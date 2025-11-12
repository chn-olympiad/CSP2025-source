#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int num[1000001],cnt=0;;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	int l=strlen(a+1);
	for(int i=1;i<=l;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			num[++cnt]=a[i]-'0';
		}
	}
	sort(num+1,num+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
	{
		printf("%d",num[i]);
	}
	return 0;
}
