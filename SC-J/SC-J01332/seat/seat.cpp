#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+1+n*m,cmp); 
	int num=1;
	
	for(int i=1;i<=m;i++)
	{
		if(m%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[num]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				num++;
			}
		
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(a[num]==a1)
				{
					cout<<i<<" "<<j;
					return 0;
				 } 
				 num++;
			}
		}
	 } 
	return 0;
}