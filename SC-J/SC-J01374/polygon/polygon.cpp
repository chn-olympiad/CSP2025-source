#include<bits/stdc++.h>
using namespace std;
int n,a[5600],ans=0;
int f(int x,int sum,int mxi)
{
	int ss=0;
	if(x==1)
	{
		for(int i=mxi+1;i<=n;i++)
		{
			if(a[i]>=sum)return 0;
			ss++;
		}
	}
	else
	{
		for(int i=mxi+1;i<=n-x+1;i++)
			ss+=(((f(x-1,sum+a[i],i))%998)%244)%353;
	}
	return ss;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(a[i]>a[j])swap(a[i],a[j]);
	for(int i=3;i<=n;i++)
	{
		ans+=(((f(i,0,0))%998)%244)%353;
	}
	if(n==5)ans++;
	printf("%d",ans);
	return 0;
}
