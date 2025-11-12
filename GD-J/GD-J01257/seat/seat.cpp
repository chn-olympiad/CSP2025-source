#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],b[15][15],sum=1,ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	//freopen("numder.in","r",stdin);
	//freopen("numder.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			ans=a[i];
		} 
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				b[j][i]=a[sum];
				if(a[sum]==ans)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				sum++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				b[j][i]=a[sum];
				if(a[sum]==ans)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				sum++;
			}
		}
	}
	return 0;
} 
