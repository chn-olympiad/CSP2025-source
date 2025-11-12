#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s[20][20];
int cmp(int a,int b) {return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				s[j][i]=a[++cnt];
				if(a[cnt]==x)
				{
					printf("%d %d\n",i,j);
					fclose(stdin);
					fclose(stdout);
					return 0;
				} 
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				s[j][i]=a[++cnt];
				if(a[cnt]==x)
				{
					printf("%d %d\n",i,j);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
}
