#include<cstdio> 
using namespace std;
char s;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(;;)
	{
		s=getchar();
		if(s>='0'&&s<='9')
		{
			a[s-'0']++;
		}
		if(s=='\n')
		{
			break;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=a[i];j>0;j--)
		{
			printf("%d",i);
		}
	}
	return 0;
}
