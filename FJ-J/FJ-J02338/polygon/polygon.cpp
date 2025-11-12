#include<bits/stdc++.h>
using namespace std;
int ans,n,a[5],num,i,j;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i=i+1)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		ans=max(a[1],a[2]);
		ans=max(a[3],ans);
		if((a[1]+a[2]+a[3]-ans)>ans)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		for(i=1;i<=n;i=i+1)
		{
			ans=max(ans,a[i]);
		}
		if((a[1]+a[2]+a[3]+a[4]-ans)>ans)
		{
			num=num+1;
		}
		ans=0;
		for(i=1;i<=4;i=i+1)
		{
			for(j=1;j<=4;j=j+1)
			{
				if(j!=i)
				{
					ans=max(ans,a[j]);
				}
			}
			if((a[1]+a[2]+a[3]+a[4]-a[i]-ans)>ans)
			{
				num=num+1;
			}
		}
		cout<<num;
	}
return 0;
}

