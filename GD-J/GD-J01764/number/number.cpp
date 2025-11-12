#include<cstdio>
#include<iostream>
using namespace std;
int sum[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char temp;
	scanf("%c",&temp);
	while(temp!='\n')
	{
		if(temp>='a' && temp<='z')
		{
			scanf("%c",&temp);
			continue;
		}
		int num=temp-'0';
		sum[num]++;
		scanf("%c",&temp);
	}
	for(int i=9;i>=0;i--)
	{
		while(1)
		{
			if(sum[i]<=0)
			{
				break;
			}
			printf("%d",i);
			sum[i]--;
		}
	}
	return 0;
}
