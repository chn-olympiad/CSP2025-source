#include<cstdio>
int n,m;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		putchar('0');
		if(i<m)putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}