#include<bits/stdc++.h>
using namespace std;
int num[1000005],len,cnt;
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			num[cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		printf("%d",num[i]);
	}
	return 0;
}
