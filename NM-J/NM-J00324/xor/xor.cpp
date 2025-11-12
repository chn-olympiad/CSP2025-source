#include<bits/stdc++.h>
using namespace std;
int sum[30][1100],as[100000][2],maxws,maxas;
void write(int x,int num)
{
	int a[30],numa=0,i;
	memset(a,0,sizeof(a));
	while(x)
	{
		++numa;
		a[numa]=x%2;
		x/=2;
	}
	int n=max(maxws,numa);
	for(i=1;i<=n;++i)
	{
		sum[i][num]=sum[i][num-1]+a[i];
	}
	maxws=n;
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j,l,x,ans=0;
	scanf("%d%d",&n,&k);
	write(k,n+1);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);
		write(x,i);
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;i+j-1<=n;++j)
		{
			int pd=0;
			for(l=1;l<=maxws;++l)
			{
				if((sum[l][i+j-1]-sum[l][i-1])%2!=sum[l][n+1]%2)
				{
					pd=1;
					break;
				}
			}
			if(!pd)
			{
				int maxw=0,maxl=0;
				for(l=1;l<=maxas;++l)
				{
					if(as[l][0]<i)
					{
						if(maxl<as[l][1])
						{
							maxl=as[l][1];
							maxw=l;
							pd=1;
						}
					}
				}
				if(!pd)
				{
					++maxas;
					as[maxas][0]=i+j-1;
					++as[maxas][1];
				}
				else
				{
					as[maxw][0]=i+j-1;
					++as[maxw][1];
				}	
			}
		}
		
	}
	for(i=1;i<=maxas;++i) ans=max(ans,as[i][1]);
	printf("%d",ans);
	return 0;
}
