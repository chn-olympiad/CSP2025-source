#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,sum,ans,maxa;
int a[5006];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			l=i;
			r=j;
			for(int k=l;k<=r;k++)
			{
				sum+=a[k];
				if(a[k+1]>a[k]) maxa=a[k+1];
			}
			if(sum>2*maxa) ans++; 
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
