#include<bits/stdc++.h>
using namespace std;

int check(char s[])
{
	int len=0;
	while(1)
	{
		if(s[len]==0)return len;
		len++;
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len=0;
	char s[100001],item1;
	while(1)
	{
		cin>>item1;
		if(item1)
		{s[len]=item1;
		len++;}
		else break;
	}
	int num[100001],p=0,item;
	for(int i=0;i<check(s);i++)
	{
		if(s[i]>='1' && s[i]<='9')
		{
		num[p]=int(s[i]);
		p++;
		}
	}
	for(int i=0;i<check(s)-1;i++)
	{
		for(int j=i;j<check(s)-1;j++)
		{
			if(num[j]<num[j+1])
			{
				item=num[j];
				num[j]=num[j+1];
				num[j+1]=item;
			}
		}
	}
	for(int i=0;i<check(s);i++)
	{
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
