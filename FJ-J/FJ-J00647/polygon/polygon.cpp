#include<bits/stdc++.h>
using namespace std;
int n,ans,sum,maxn;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			sum=0;
			maxn=0;
			for(int o=j;o<=j+i-1;o++)
			{
				sum+=a[o];
				maxn=max(maxn,a[o]);
			}
			if(sum>maxn*2)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
