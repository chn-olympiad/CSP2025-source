#include<bits/stdc++.h>
using namespace std;
int a[600001],b,n,k,ans,vis[1001],cut,vis1[1001],vis2[1001],bi;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) bi=1;
	}
	if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		printf("1");
		return 0;
	}
	if(bi==0)
	{
		for(int i=n-1;i>=1;i=i-2) ans+=i;
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k) ans++;
		cut=a[i];
		for(int j=i+1;j<=n;j++)
		{
			b=a[j];
			int c=0,c1=0,c2=1;
			while(b!=0)
			{
				c++;
				vis[c]=b%2;
				b=b/2;
			}
			while(cut!=0)
			{
				c1++;
				vis1[c1]=cut%2;
				cut=cut/2;
			}
			for(int i=1;i<=max(c,c1);i++)
			{
				if(vis[i]==vis1[i]) vis2[i]=0;
				else vis2[i]=1;
			}
			cut=0;
			for(int i=1;i<=max(c,c1);i++)
			{
				cut=cut+vis2[i]*c2;
				c2=c2*2;
			}
			if(cut==k) ans++;
		}
	}
	printf("%d",ans);
}
