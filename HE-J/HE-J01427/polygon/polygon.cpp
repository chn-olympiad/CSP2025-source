#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	int ans=0;
	int ma=-1;
	for(int i=1;i<=n;++i)
	{
		ans+=a[i];
		ma=max(ma,a[i]);
	}
	ma=ma*2;
	int t=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n-1;++j)
		{
			for(int l=j;l<=n;++l)
			{
				if(l!=i&&l!=j)
				{
					int mx=-1;
					mx=max(a[i],max(a[j],a[l]));
					if(a[i]+a[j]>a[l]&&a[i]+a[l]>a[j]&&a[l]+a[j]>a[i])
					{
						t++;
					}
				}
			}
		}
	}
	int t1=0;
	for(int i=ma;i<=ans;++i)
	{
		t1++;
	 } 
	cout<<t1+t;
}
