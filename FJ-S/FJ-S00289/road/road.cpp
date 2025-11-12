#include<bits/stdc++.h>
#define N 1000000000
#define ll long long
using namespace std;
ll n,m,k,cnt,mina,al,alll,mp[10011][10011],lik[10011];
ll u,v,w[1000010],c[1000010],a[100][10010];
//void seac(int sta,int pin)
//{
//	for(int k=1;k<=n;k++)
//	{
//		if(mp[sta][k]!=0)
//		{
//			lik[k]=pin;
//			seac(k,pin);
//		}
//	}
//	return;
//}
//void bfs(int star,int cos,int man)
//{
//	if(man==n)
//	{
//		return;	
//	}
//	for(int q=1;q<=n;q++)
//	{
//		if(mp[star][q]!=0)
//		{
//			bfs(q,mp[star][q],man++);
//		}
//	}
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w[i]);
		alll+=w[i];
		mp[u][v]=w[i];
		mp[v][u]=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[k][j]);
			mp[k+n][j]=a[k][j];
			mp[j][k+n]=a[k][j];
		}
	}
//	wh=0;
//	for(int i=1;i<=n;i++)
//	{
//		if(lik[i]==0)
//		{
//			lik[i]=++wh;
//			seac(i,wh);
//		}
//	}
//	for(int i=1;i<=wh;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(lik[j]==i)
//			{
//				
//			}
//		}
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int o=1;o<=k;o++)
			{
				if(mp[i][j]>mp[i][o+n]+mp[o+n][j]+c[o])
				{
					mp[i][j]=mp[i][o+n]+mp[o+n][j]+c[o];
				}
				else if(mp[i][j]==0)
				{
					mp[i][j]=N;
					mp[i][j]=min(mp[i][j],mp[i][o+n]+mp[o+n][j]+c[o]);
				}
			}
		}
	}
	for(int q=1;q<=n+k-1;q++)
	{
		mina=N;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mina=min(mina,mp[i][j]);
			}
		}
		al+=mina;
	}
	printf("%lld",alll);
	return 0;
}
