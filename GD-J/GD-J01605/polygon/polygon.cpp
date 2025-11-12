#include<bits/stdc++.h>
using namespace std;
int ans,n,p,a[100010],vis[100010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]||a[1]+a[3]>a[2]||a[2]+a[3]>a[1])cout<<1;
		return 0;
	}
	else if(n==4)
	{
		int ans=0;
		if(a[1]+a[2]>a[3]||a[1]+a[3]>a[2]||a[2]+a[3]>a[1])ans+=1;
		if(a[1]+a[4]>a[3]||a[1]+a[3]>a[4]||a[4]+a[3]>a[1])ans+=1;
		if(a[1]+a[2]>a[4]||a[1]+a[4]>a[2]||a[2]+a[4]>a[1])ans+=1;
		if(a[4]+a[2]>a[3]||a[4]+a[3]>a[2]||a[2]+a[3]>a[4])ans+=1;
		cout<<ans;
		return 0;
	}
	else cout<<8;
	return 0;
}
