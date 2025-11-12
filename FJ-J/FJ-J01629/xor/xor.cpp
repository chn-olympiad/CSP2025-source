#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[11005],f[11005][11005],f2[11005][11005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		f[i][i]=a[i];
		if(a[i]==k) f2[i][i]=1;
	}
	//	for(int m=2;m<=n;m++)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			int j=i+m-1;
//			for(int k=i;k<=j;k++) 
//			{
//				f[i][j]=max(f[i][j],f[i][k] xor f[k+1][j]);
//				if(f[i][j]==k) f2[i][j]=1;
//			}
//		}
//	}
	for(int m=2;m<=n;m++)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+m-1;
			f[i][j]=f[i][i] xor f[i+1][j];
			if(f[i][j]==k) f2[i][j]=1;
		}
	}
	for(int m=2;m<=n;m++)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+m-1;
			for(int k=i;k<=j;k++) 
			{
				f2[i][j]=max(f2[i][j],f2[i][k]+f2[k+1][j]);
			}
		}
	}
	cout<<f2[1][n];
	return 0;
}
