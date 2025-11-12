#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[101],r=0,n,m,sum=1,dd=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	for(int j=1;j<=n*m;j++)
	{
		for(int k=1;k<=(n*m)-j;k++)
		{
			if(a[k]<a[k+1])
			{
				swap(a[k],a[k+1]);
			}
		}
	}  
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]!=r)
		{
			sum+=1;
		}
		if(a[i]==r)
		{
			break;
		}
	}
	if(sum%m==0)
	{
		cout<<sum/m<<' '<<m;
	}
	if(sum%m!=0)
	{
		cout<<(sum/m)+1<<' ';
		if((sum/m)%2==0)
		{
			cout<<abs(m-(sum-((sum/m)*m)))-1;
		}
		if((sum/m)%2!=0)
		{
			cout<<sum-((sum/m)*m);
		}
	}
	return 0;
}
