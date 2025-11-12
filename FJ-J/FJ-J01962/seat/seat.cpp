#include<bits/stdc++.h>
using namespace std;
bool px(int x,int y)
{
	return x>y;
}
int a[157];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cj,dj,k,q,h,l,sum=0;//cj 成绩，dj 第几名 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+1+n*m,px);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==cj)
		{
			dj=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				sum++;
				if(sum==dj)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				sum++;
				if(sum==dj)
				{
					cout<<i<<" "<<j;
					return 0;
				}				
			}
		}
	}

	return 0;
}
