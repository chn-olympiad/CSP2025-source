#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll a[N][4],T,dp[N][4],f[N][4][5],n,r;
ll read()
{
	ll a=0,j=1;char b=getchar();
	for(;b>'9'||b<'0';b=getchar())if(b=='-') j=-1;
	for(;b>='0'&&b<='9';a=a*10+b-48,b=getchar());
	return a*j;
}
void cmp()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][1]<a[j][1])
			{
				swap(a[i][1],a[j][1]);
				swap(a[i][2],a[j][2]);
				swap(a[i][3],a[j][3]);
			}
			else if(a[i][1]==a[j][1]&&a[i][2]<a[j][2])
			{
				swap(a[i][1],a[j][1]);
				swap(a[i][2],a[j][2]);
				swap(a[i][3],a[j][3]);
			}
			else if(a[i][1]==a[j][1]&&a[i][2]==a[j][2]&&a[i][3]<a[j][3])
			{
				swap(a[i][1],a[j][1]);
				swap(a[i][2],a[j][2]);
				swap(a[i][3],a[j][3]);
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof(f));
		n=read();
		r=n/2;
		for(int i=1;i<=n;i++) a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		cmp();
  		f[1][1][0]=a[1][1];f[1][2][0]=a[1][2];f[1][3][0]=a[1][3];
		f[1][1][1]=1;f[1][1][2]=0;f[1][1][3]=0;f[1][2][1]=0;f[1][2][2]=1;f[1][2][3]=0;f[1][3][1]=0;f[1][3][2]=0;f[1][3][3]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
						if(f[i-1][k][j]<r)
						{
							if(f[i-1][k][0]+a[i][j]>f[i][j][0])
							{
								for(int y=1;y<=3;y++)
								{
									f[i][j][y]=f[i-1][k][y];
								}
								f[i][j][j]++;
								f[i][j][0]=f[i-1][k][0]+a[i][j];
							}
						}
				}
			}
		}
		cout<<max(f[n][1][0],max(f[n][2][0],f[n][3][0]))<<endl;	
	}
	return 0;
}