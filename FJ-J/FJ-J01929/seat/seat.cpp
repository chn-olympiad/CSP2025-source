#include<bits/stdc++.h>
using namespace std;
const int N=1e1+10;
int n,m;
int a[N*N],a1,d,tot;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(i==1)
		{
			a1=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	tot=1;
	for(int i=1;i<=m;i++)
	{
		//枚举 列 
		if(i%2==0)
		{
			//从下向上排座位
			for(int j=n;j>=1;j--)
			{
				if(a[tot]==a1)
				{
					printf("%d %d",i,j);
					return 0;
				}else{
					tot++;
				}
			}
		}else{
			//从上向下排座位
			for(int j=1;j<=n;j++)
			{
				if(a[tot]==a1)
				{
					printf("%d %d",i,j);
					return 0;
				}else{
					tot++;
				}
			}
		}
	}
	return 0;
}

