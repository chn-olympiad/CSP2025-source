#include<bits/stdc++.h>
using namespace std;
int roll[29],v;
char dz;
char s[1145141];
bool f;
bool is_dig(int n)
{
	if(n>='0'&&n<='9')return 1;
	return 0;
}
bool is_lowchar(int n)
{
	if(n>='a'&&n<='z')return 1;
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1)
	{
		dz=getchar();
		if(is_dig(dz)||is_lowchar(dz))s[++v]=dz;
		else break;
	}
	for(int i=1;i<=v;i++)
	{
		if(is_dig(s[i]))
		{
			roll[s[i]-'0']++;
			if(s[i]>='1')f=1;
		}
	}
	if(!f)
	{
		printf("0");
	}
	else
	{
		for(int i=9;i>=0;i--)
		{
			for(int j=1;j<=roll[i];j++)printf("%d",i);
		}
	}
	return 0;
}
