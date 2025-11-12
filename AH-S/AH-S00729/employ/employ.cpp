#include <bits/stdc++.h>
using namespace std;
int f[512],x[512];
int c[2][270012][20];
int pc[270012];
const int P=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,C=1;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		C=1ll*C*i%P;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		f[x[i]]++;
	}
	s=' '+s;
	if(n<=18)
	{
		for(int i=1;i<(1<<n);i<<=1)
			for(int j=0;j<(1<<n);j++)
				if(j&i) pc[j]++;
		c[0][0][0]=1;
		for(int i=1;i<=n;i++)
		{
			memset(c[i&1],0,sizeof c[i&1]);
			for(int j=0;j<(1<<n);j++)
			{
				if(pc[j]!=i-1) continue;
				for(int k=0;k<i;k++)
					for(int ii=1,jj=1;ii<(1<<n);ii<<=1,jj++)
					{
						if(j&ii) continue;
						if(k<x[jj]&&s[i]=='1')
						{
							c[i&1][j|ii][k]+=c[1-(i&1)][j][k];
							if(c[i&1][j|ii][k]>=P) c[i&1][j|ii][k]-=P;
						}
						else
						{
							c[i&1][j|ii][k+1]+=c[1-(i&1)][j][k];
							if(c[i&1][j|ii][k+1]>=P) c[i&1][j|ii][k+1]-=P;
						}
					}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)
		{
			ans+=c[n&1][(1<<n)-1][i];
			if(ans>=P) ans-=P;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==1)
	{
		int ans=1,h=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0') continue;
			for(int j=0;j<=i-1;j++)
				h+=f[j];
			ans=1ll*ans*max(h,0)%P;
			for(int j=0;j<=i-1;j++)
				h-=f[j];
			h--;
		}
		for(int i=1;i<=n+h;i++)
			ans=1ll*ans*i%P;
		ans=C-ans;
		if(ans<0) ans+=P;
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
// 17:30 - 17:50, 0 / 100 points
// 17:50 - 18:05, 20 / 100 points
// 18:05 - 18:25, 32 / 100 points
// 18:25 - 18:30, 32 / 100 points
