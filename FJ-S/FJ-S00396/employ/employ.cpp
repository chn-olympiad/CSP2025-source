#include<cstdio>
using namespace std;

int n,m;
char s[505];
int a[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++)
	{	scanf("%d",&a[i]);	}
	
	if(m==n)
	{	for(int i=0;i<=strlen(s);i++)
		{	if(s[i]=='0')
			{	printf("0");	}
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

