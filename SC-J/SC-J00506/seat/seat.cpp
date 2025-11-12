#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,ans;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1]; 
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[(i-1)*n+j]==ans)
			{
				cout<<i<<" "<<j;
			}
		}
		if(m%2==1&&i==m)continue;
		for(int j=n;j>=1;j--)
		{
			if(a[i*n+j]==ans)
			{
				cout<<i+1<<" "<<n-j+1;
			}
		}
	}
	return 0;
}