#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[200],n,m,r,c,x=0,bb=0;
bool comp(int a,int b)
{
	if(a>b) return true;
	return false;
}
int main()
{
	/*if(freopen("seat1.in","r",stdin)==NULL)
	{
		perror("重定向错误");
		return 1;
	}
	if(freopen("seat1.out","w",stdout)==NULL)
	{
		perror("重定向错误");
		return 1;
	}
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);*/
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&b[i]);
		if(i==0) x=b[i];
	}
	sort(b,b+n*m,comp);
	for(int i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<n;j++)
			{
				a[j][i]=b[bb];
				bb++;
			}
		}
		else
		{
			for(int j=n-1;j>=0;j--)
			{
				a[j][i]=b[bb];
				bb++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==x)
			{
				printf("%d %d",j+1,i+1);
				break;
				break;
			}
		}
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		cout<<endl;
	}*/
	return 0;
}