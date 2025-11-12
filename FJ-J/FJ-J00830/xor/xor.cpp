#include<bits/stdc++.h>
using namespace std;
int a[500010],f[1010][1010],ff[1010][1010],maxn=-1,n,k,k1;
int wh(int a,int b)
{
	long long k=0,sum=0;
	while(a||b)
	{
		if(a%2!=b%2)
			sum+=pow(2,k);
		a/=2;
		b/=2;
		k++;
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			f[i][j]=wh(a[j],f[i][j-1]);
			int y;
			y=(f[i][j]==k1);
			ff[i][j]=max(ff[i][j-1],y);
			
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<j;k++)
			{
				int z;
				z=(f[k+1][j]==k1);
				ff[i][j]=max(ff[i][j],ff[i][k]+z);
			}
		}
	}
	cout<<ff[1][n];
	return 0;
}

