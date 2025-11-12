#include<iostream>
using namespace std;
int m,n;
int a[9999],p[9999];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf(" %d%d",&n,&m);
	for(int i=1;i<=m*n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1,maxn,pos;i<=n*m;i++)
	{
		maxn=-99999;pos=-1;
		for(int j=1;j<=n*m;j++)
		{
			if(a[j]>maxn&&p[j]==0)
			{
				maxn=a[j];pos=j;
			}
		}
		p[pos]=i;
	}
	int x=1,y=1;//y––x¡–
	//cout<<p[1]<<endl;
	for(int i=p[1];i>1;i--)
	{
		if(y==n&&x%2==1||y==1&&x%2==0)
		{
			x++;
		}
		else
		{
			if(x%2==1)
			{
				y++;
			}
			if(x%2==0)
			{
				y--;
			}
		}
		//cout<<x<<" "<<y;
	}
	cout<<x<<" "<<y;
}
