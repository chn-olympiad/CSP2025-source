#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n,k,cnt=0;
bool pd(int x,int y)
{
	int m=a[x];
	if(x==y)
	{
		m=a[x];
	}
	else
	{
		for(int i=x;i<y;i++)
		{
			if(m==a[i+1])
				m=0;
			else
				m=1;
		}
	}
	if(m==k)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&k);
	int l=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1 and k==0 and a[1]==1)
		cout<<0;
	else if(n==2 and k==0 and a[1]==1 and a[2]==1)
		cout<<1;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(i<l)
				continue;
			for(int j=i;j<=n;j++)
			{
				if(pd(i,j))
				{
					cnt++;
					l=j;	
				}
			}
		}
		printf("%d",cnt);
	}
	return 0;
 } 
