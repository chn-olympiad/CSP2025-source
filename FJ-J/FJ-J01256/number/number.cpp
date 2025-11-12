#include<bits/stdc++.h>
using namespace std;
char s[1000100];
int num[1000100],j=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gets(s);
	for(int i=0;s[i];i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num+1,num+j,cmp);
	for(int i=1;i<j;i++)
		printf("%d",num[i]);
}