#include<bits/stdc++.h>
using namespace std;

const int N =1e5+5;

int t,n,aa[N],bb[N],cc[N],sat,cba,cbb,cbc,cntb,cntc;
bool vis[N];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		sat=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&aa[i],&bb[i],&cc[i]);
		}
		
		//sort(cc+1,cc+n+1);
		memset(vis,0,sizeof vis);
		cba=0,cbb=0,cbc=0;
		cntb=0,cntc=0;
		for(int i=1;i<=n;i++)
		{
			if(bb[i]==0) cntb++;
			if(cc[i]==0) cntc++;
		}
		
		if(cntb==n && cntc==n)
		{
			sort(aa+1,aa+n+1);
			for(int i=n;i>=1;i--)
			{
				if(cba<(n/2))
				{
					if(!vis[i])
					{
						sat+=aa[i];
						vis[i]=1;
						cba++;
					}
				}
			}
		}
		
		else if(cntc==n)
		{
			sort(bb+1,bb+n+1);
			sort(aa+1,aa+n+1);
			for(int i=1;i<=n;i++)
			{
				if(!vis[i])
				{
					if(aa[i]>bb[i])
					{
						if(cba<(n/2))
						{
							sat+=aa[i];
						}
						else
						{
							if(cbb<(n/2))
							{
								sat+=bb[i];
							}
						 } 
						
					}
					else 
					{
						if(cbb<(n/2))
						{
							sat+=bb[i];
						}
						else
						{
							if(cba<(n/2))
							{
								sat+=aa[i];
							}
						}
					}
				}
				vis[i]=1;
			}
		}
		
		else 
		{
			for(int i=1;i<=n;i++)
			{
				if(cba<(n/2))
				{
					if(!vis[i])
					{
						sat+=aa[i];
						vis[i]=1;
						cba++;
					}
				}
				for(int j=1;j<=n;j++)
				{
					if(cbb<(n/2))
					{
						if(!vis[j])
						{
							sat+=bb[j];
							vis[j]=1;
							cbb++;
						}
					}
					for(int k=1;k<=n;k++)
					{
						if(cbc<(n/2))
						{
							if(!vis[k])
							{
								sat+=cc[k];
								vis[k]=1;
								cbc++;
							}
						}
					}
				}
			}
		}
		cout<<sat;
	}
	return 0;
} 
