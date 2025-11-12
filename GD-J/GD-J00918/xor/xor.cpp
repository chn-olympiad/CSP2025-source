#include<bits/stdc++.h>
using namespace std;
#define int long long
int z,x,a[500005],okA=1,okB=1,q,s[1005][1005],vis[500005];
signed main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&z,&x);
	for(int i=1;i<=z;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==0)  q++;
		if(a[i]!=1)  okA=0;
		if(a[i]!=1&&a[i]!=0)  okB=0;
	}
	if(okA==1||okB==1)
	{
		int ans=0,sum=0;
		for(int i=1;i<=z;i++)
		{
			if(a[i]==1)  sum++;
			sum%=2;
			if(sum==x)  ans++,sum=0;
		}
		if(x==0)  printf("%lld",max(q,ans));
		else  printf("%lld",ans);
	}
	else
	{
		for(int i=1;i<=z;i++)
		{
			for(int j=i;j<=z;j++)
			{
				int sum=a[i];
				for(int t=i+1;t<=j;t++)  sum=(sum xor a[t]);
				s[i][j]=sum;
			}
		}
		int ans=0;
		for(int i=1;i<=z;i++)
		{
			for(int j=i;j<=z;j++)
			{
				if(s[i][j]==x&&vis[j]==0)
				{
					ans++;
					for(int t=1;t<=j;t++)  vis[t]=1;
					break;
				}
			}
		}
		int ans1=0;
		memset(vis,0,sizeof vis);
		for(int i=z;i>=1;i--)
		{
			int qq=0;
			for(int j=z;qq<=i;j--)
			{
				qq++;
				if(s[i][j]==x&&vis[j]==0)
				{
					ans1++;
					for(int t=j;t<=z;t++)  vis[t]=1;
					break;
				}
			}
		}
		printf("%lld",max(ans1,ans));
	}
	
	return 0;
}
