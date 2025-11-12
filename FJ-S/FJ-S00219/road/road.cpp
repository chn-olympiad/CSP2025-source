#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=10010;
ll x,y,z,f[N][N],sum[N],q[N],n,m,k,Ans=0x7f;
ll read()
{
	ll a=0,j=1;char b=getchar();
	for(;b>'9'||b<'0';b=getchar())if(b=='-') j=-1;
	for(;b>='0'&&b<='9';a=a*10+b-48,b=getchar());
	return a*j;
}
int main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;i++) 
	{
		x=read();y=read();z=read();
		f[x][y]=z;f[y][x]=z;
	}
	for(int i=1;i<=k;i++)
	{
		q[i]=read();
		for(int j=1;j<=n;j++)
		{
			f[i+n][j]=read();
			f[j][i+n]=f[i+n][j];
		}
		sum[i]=sum[i-1]+q[i];
	}
	for(int l=0;l<=k;l++)
	{
		for(int o=0;o<l;o++)
		{
			for(int p=1;p<=n+l;p++)
			{
				for(int i=1;i<=n+l;i++)
				{
					for(int j=1;j<=n+l;j++)
					{
						if(p<o+n&&f[i][p]!=-1&&f[p][j]!=-1)
							f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
					}
				}
			}	
			Ans=min(Ans,f[1][n]+sum[l]-sum[o-1]);
		}
	}
	cout<<Ans;
	return 0;
}