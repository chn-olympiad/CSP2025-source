#include<iostream>
#include<cstdio>
using namespace std;
int sum[500005],n,k,ans,w,flag[150000],j;
bool again,vis[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	flag[0]=1;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w);
		sum[i]=sum[i-1]^w;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[k^sum[i]])
		{
			again=0;
			for(j=flag[k^sum[i]];j<=i;j++)
			{
				if(vis[j]==1)
				{
					again=1;
					break;
				}
			}
			if(!again)
			{
				ans++;
				for(j=flag[k^sum[i]];j<=i;j++) vis[j]=1;
			}
		}
		flag[sum[i]]=i+1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
