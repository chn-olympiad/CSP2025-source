#include <cstdio>
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long int s[10]={0};
	for(char c=getchar();c!=EOF;c=getchar())
	{
		if(c>='0'&&c<='9')
		{
			s[c-'0']++;
		}
	}
	long long int h=0;
	for(int i=9;i>=0;i--)
	{
		if(s[i])
		{
			for(long long int k=0;k<s[i];k++)
			{
				printf("%d",i);
			}
		}
	}
	return 0;
}
