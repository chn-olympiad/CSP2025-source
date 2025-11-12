#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,cnt,maxn;
int f[3005][3005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=f[i][j-1]^a[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		int l=i,r=i;
		while(l<=n&&r<=n)
		{
			if(f[l][r]==k)
			{
				cnt++;
				l=r+1;
			}
			r++;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
