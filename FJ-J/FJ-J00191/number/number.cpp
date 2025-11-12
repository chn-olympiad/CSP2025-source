#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int max[10]={0};
	while((s=getchar())!='\n')
	{
		if(s>='0'&&s<='9')
		{
			max[s-48]+=1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(max[i]>0)
		{
			for(int j=1;j<=max[i];j++)
			{
				cout<<i;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}