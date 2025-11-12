#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],x[500005],y[500005],a1,b1;
int f[5005][50005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=a[i];
		if(f[i][i]==k)
		{
			x[++a1]=i;
			y[++b1]=i;
		}
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=f[i][j-1]^a[j];
			if(f[i][j]==k)
			{
				x[++a1]=i;
				y[++b1]=j;
			}
		}
	}
	if(x[1]==0)
	{
		cout<<0;
		return 0;
	}
	int x1=0,y1=0,ans=0;
	for(int i=1;i<=a1;i++)
	{
		if((x1<x[i]&&y1<x[i])||(x1>x[i]&&y1>y[i]))
		{
			ans++;
			x1=x[i];
			y1=y[i];
		}
	}
	cout<<ans;
	return 0;
}
