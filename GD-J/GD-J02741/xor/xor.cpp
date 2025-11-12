#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[1005][1005],bz,cnt,b;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0&&k==0)
		{
			cnt++; 
			bz=1;
		}
		if(a[i]==1&&k==1)
		{
			cnt++;
			bz=1;
		}
	}
	if(bz==1)
	{
		cout<<cnt;
		return 0;
	}
	int d=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int m=0;
			for(int q=i;q<=j;q++)
			{
				m^=a[q];
			}
			if(m==k)
			{
				f[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=max(f[i][j-1],max(f[i][j],f[i-1][j+1]-f[i-1][1]-f[j][j+1]));
		}
	}
	cout<<f[1][n]+1;
	return 0;
}
