#include<iostream>
using namespace std;
long long n,k,a[1000005],b[10005][10005],sum;
void xoring()
{
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(i==j)
			{
				b[i][j]=a[i];
			}
			else
			{
				b[i][j]=b[i][j-1] xor a[j];
			}
		}
	}
}
void find(long long i,long long j,long long ans)
{
	if(j>i||i>n||i>n)
	{
		sum=max(sum,ans);
		return;
	}
	if(b[i][j]==k)
	{
		find(i+1,j,ans);
		find(i,j+1,ans);
		long long maxx=max(i,j);
		find(maxx+1,maxx+1,ans+1);
	}
	find(i+1,j,ans);
	find(i,j+1,ans);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool frog=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			frog=1;
		}
	}
	if(k==0&&frog==0)
	{
		cout<<n;
		return 0;
	}
	xoring();
	find(1,1,0);
	cout<<sum;
	return 0;
}
