#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;
int n,m,a[105],a1,now=1,ansi,ansj;
bool found;
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	a1=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i^(0-i)==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[now]==a1)
				{
					ansj=j;
					found=1;
					break;
				}
				now++;
			}
		}
		else
		{
			for(int j=n;j;j--)
			{
				if(a[now]==a1)
				{
					ansj=j;
					found=1;
					break;
				}
				now++;
			}
		}
		if(found)
		{
			ansi=i;
			break;
		}
	}
	printf("%d %d",ansi,ansj);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
