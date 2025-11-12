#include<cstdio>
int n=0,a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(char c=getchar();c!=-1;c=getchar())
	{
		if(c>='0'&&c<='9')
		{
			++a[c^48];
		}
	}
	for(int i=9;i>=0;--i)
	{
		while(a[i]>0)
		{
			putchar(i|48);
			--a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}