#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX 200

#define UP 1
#define DOWN 2

int a[MAX];
int n,m;
int seats[14][14];

void DFS(int direct,int cur,int lie)
{
	if(cur>n*m)
		return ;
	if(direct==DOWN)
	{
		for(int i=1;i<=n;i++)
		{
			seats[i][lie]=a[cur+i-1];
		}
		DFS(UP,cur+n,lie+1);
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			seats[n-i+1][lie]=a[cur+i-1];
		}
		DFS(DOWN,cur+n,lie+1);
		return ;
	}
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int finder=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	DFS(DOWN,1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(seats[i][j]==finder)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
