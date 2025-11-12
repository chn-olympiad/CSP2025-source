#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int R;
int flag;
int maps[110][110];
bool node(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(maps,0,sizeof(maps));
	scanf("%d %d",&n,&m);
	scanf("%d",&a[1]);//a[1]是小R的分数 
	R=a[1];
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1,node);
	int flag=1;//记录上一次遍历最后的下标 
	for(int i=1;i<=m;i++)//先列再行 
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				maps[i][j]=a[flag];
				if(maps[i][j]==R)
				{
					printf("%d %d",i,j);
					return 0;
				}
				flag++;
			}
		}
		else
		{
			for(int j=n;j>0;j--)
			{
				maps[i][j]=a[flag];
				if(maps[i][j]==R)
				{
					printf("%d %d",i,j);
					return 0;
				}
				flag++;
			}
		}
	}
	return 0;
}
