#include<bits/stdc++.h>
using namespace std;
int mp[5][100010];
int b[10];
int a1[100010];
int a2[100010];
int a3[100010];
int num[20010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	int t,n;
	scanf("%d",&t);
	for(int sj=1;sj<=t;sj++)
	{
		int ans=0,m=0;
		scanf("%d",&n);
		if(n==2)
		{
			int bmax=-1;
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			}
			b[1]=a1[1]+a2[2];
			b[2]=a1[2]+a2[3];
			b[3]=a1[1]+a1[3];
			b[4]=a1[3]+a2[2];
			b[5]=a1[3]+a2[1];
			b[6]=a1[2]+a2[1];
			for(int i=1;i<=6;i++)
			{
				bmax=max(bmax,b[i]);
			}
			cout<<bmax;
			return 0;
		}
		int pd=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a2[i]!=0||a3[i]!=0)
			{
				pd=1;
			}
			if(pd==0)
			{
				int maxx=-1;
				for(int i=1;i<=n;i++)
				{
					num[a1[i]]++;
					maxx=max(maxx,a1[i]);
				}
				int cnt=n;
				while(cnt>0)
				{
					for(int i=maxx;i>=0;i--)
					{
						if(num[i]!=0)
						{
							if(num[i]>=cnt)
							{
								ans=ans+cnt*i;
								printf("%d",ans);
								return 0;
							}
							else{
								ans=ans+num[i]*i;
								cnt=cnt-num[i];
							}
						}
					}
				}
			}
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}