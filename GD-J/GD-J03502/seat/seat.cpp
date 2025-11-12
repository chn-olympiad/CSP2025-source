#include<bits/stdc++.h>
using namespace std;
long long ans[101][101],n,m,a[1001],p[1001],w;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	long long k=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		p[++w]=a[i];
	}
	long long t=1;
	long long j=1;
	for(int i=1;i<=m;i++)
	{
		if(j==1)
		{
			while(j<n)
			{
				ans[j][i]=p[t];
				t++;
				j++;
			}
			ans[j][i]=p[t];
			t++;
		}
		else if(j==n)
		{
			while(j>1)
			{
				ans[j][i]=p[t];
				t++;
				j--;
			}
			ans[j][i]=p[t];
			t++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==k) 
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

