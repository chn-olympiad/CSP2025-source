#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,maxn=0,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int k=n;k>=3;k--)
	{
		for(int i=1;i<=n-2;i++)
		{
			int p=i+1;
			t+=a[i];
			for(int j=p;j<=n;j++)
			{
				if(a[j]>maxn) maxn=a[j];
				t+=a[j];
			
			}
			if(t>maxn*2)
			{
			 	ans++;
				maxn=0;
				t=0;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
