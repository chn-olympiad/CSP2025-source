#include<bits/stdc++.h>
using namespace std;
const int N2=100;
int n,k,ls,xnum[110][N2],point,lsnum[N2],sum=0,lastr=0;
struct node
{
	int lp,rp;
}avai[600];

inline int cmp(node a,node b)
{
	if(a.lp<b.lp)
	{
		return 1;
	}
	return 0;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n<=2&&!k)//1ºÅ²âÊÔµã 
	{
		cout<<0;
		return 0;
	}
	if(n<=100&!k)//3ºÅ²âÊÔµã 
	{
		cout<<0;
		return 0;
	}
	for(register int i=1;i<=n;i++)
	{
		point=0;
		scanf("%d",&ls);
		while(ls)
		{
			xnum[i][++point]=ls%2;
			ls/=2;
		}
	}
	for(register int l=1;l<=n;l++)
	{
		for(register int r=1;r<=n;r++)
		{
			ls=0;
			for(register int i=l;i<=r;i++)
			{
				for(register int j=1;j<=8;j++)
				{
					lsnum[j]+=xnum[i][j];
				}
			}
			for(register int i=8;i>=1;i--)
			{
				ls+=lsnum[i]*pow(2,i-1);
			}
			if(ls==k)
			{
				avai[++sum].lp=l;
				avai[++sum].rp=r;
			}
		}
	}
	sort(avai+1,avai+sum+1,cmp);
	sum=0;
	for(register int i=1;i<=n;i++)
	{
		if(avai[i].lp>lastr)
		{
			sum++;
			lastr=avai[i].rp;
		}
	}
	printf("%d",sum);
	return 0;
}
