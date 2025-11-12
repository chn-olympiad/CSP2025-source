#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int xiangchun1[11]; 
int xiangchun[11][1000006];
long long evmoney=100000000000;
class cz
{
public:
	int n[10006]; 
	int nt[10006];
}e[10006];
bool viscz[10006];
void zwei(long long ttmoney,int k)
{
	viscz[k]=1;
	int zzz=0;
	for(int i=1;i<=n;i++)
	{
		if(viscz[i]==1)
		{
			zzz++;
		}
		if(zzz==n)
		{
			if(evmoney>=ttmoney)
			{
				evmoney=ttmoney;
			}
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(viscz[i]==0&&e[k].nt[i]==1)
		{
			ttmoney+=e[k].n[i];
			zwei(ttmoney,i);
			ttmoney-=e[k].n[i];
			viscz[k]=0;
		}
	}
}
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++)
	{
		int a,b,money;
		cin>>a>>b>>money;
		e[a].n[b]=money;
		e[b].n[a]=money;
		e[a].nt[b]=1;
		e[b].nt[a]=1;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>xiangchun1[i];
		for(int j=1;j<=n;j++)
		{
			cin>>xiangchun[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int z=1;z<=n;z++)
			{
				long long ans;
				ans=xiangchun1[i]+xiangchun[i][j]+xiangchun[i][z];
				if(ans<=e[z].n[j]||e[j].nt[z]!=1)
				{
					e[z].n[j]=ans;
					e[j].n[z]=ans;
					e[z].nt[j]=1;
					e[j].nt[z]=1;
				}
			}
		}
	}
	zwei(0,1);
	cout<<evmoney;
}
