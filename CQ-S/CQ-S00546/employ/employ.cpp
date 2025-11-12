#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+5;
const int mod=998244353;
int n,m,a[N],T[N],sum[N],c[N],ans,step[N],step_inv[N],num[N],f[N][N][N][2];
string s;
int Fast(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y%2)ans=ans*x%mod;
		x=x*x%mod;
		y=y/2;
	}
	return ans;
}
int C(int n,int m)
{
	if(m>n)return 0;
	return step[n]*step_inv[n-m]%mod*step_inv[m]%mod;
}
void prepare()
{
	step[0]=1;
	for(int i=1;i<=n;i++)step[i]=step[i-1]*i%mod;
	step_inv[n]=Fast(step[n],mod-2);
	for(int i=n-1;i>=0;i--)step_inv[i]=step_inv[i+1]*(i+1)%mod;
	sum[0]=T[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+T[i];
}
void solve()
{
	f[0][0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			for(int j=0;j<=i;j++)
			{
				for(int k=0;k<=sum[j];k++)
				{
					int tmp=0;
					for(int t=0;t<=sum[j];t++)
					{
						if(j-1<0||k-t<0||(k-(j-1))<0||s[j-2]-(k-t)<0||(i-j)-(sum[max(0ll,j-2)]-(k-t)))continue;
						int dmp=0;
						dmp=(f[i-1][j-1][k-t][0]+f[i-1][j-1][k-t][1])%mod;
						dmp=dmp*C((i-j)-(sum[max(0ll,j-2)]-(k-t)),t)%mod;
						dmp=dmp*C(T[j],t)%mod*step[t]%mod;
						tmp=(tmp+dmp)%mod;
					}
					f[i][j][k][0]=tmp;
//					cout<<"cnm: "<<i<<' '<<j<<' '<<f[i][j][k][0]<<' '<<f[i][j][k][1]<<'\n';
				}
			}
//			cout<<"-------------------\n";
			continue;
		}
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=sum[j];k++)
			{
				int tmp=0;
				f[i][j][k][1]=(f[i-1][j][k][0]+f[i-1][j][k][1])%mod;
				for(int t=0;t<=sum[j];t++)
				{
					if(j-1<0||k-t<0||(k-(j-1))<0||s[j-2]-(k-t)<0||(i-j)-(sum[max(0ll,j-2)]-(k-t)))continue;
					int dmp=0;
					dmp=(f[i-1][j-1][k-t][0]+f[i-1][j-1][k-t][1])*(k-(j-1))%mod;
					dmp=dmp*C((i-j)-(sum[max(0ll,j-2)]-(k-t)),t)%mod;
					dmp=dmp*C(T[j],t)%mod*step[t]%mod;
					tmp=(tmp+dmp)%mod;
				}
				f[i][j][k][0]=tmp;
//				cout<<"cnm: "<<i<<' '<<j<<' '<<f[i][j][k][0]<<' '<<f[i][j][k][1]<<'\n';
			}
		}
//		cout<<"---------------\n";
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]!=num[n])continue;
		for(int j=1;j<=i;j++)
		{
			for(int k=0;k<=sum[j];k++)
			{
				int tmp=0,sb=sum[n]-sum[j-1];
//				cout<<"??: "<<i<<' '<<j<<' '<<f[i][j][k][0]<<' '<<sb<<' '<<sum[n]<<' '<<sum[j-1]<<'\n';
				tmp=f[i][j][k][0]*step[sb]%mod;
				ans=(ans+tmp)%mod;
			}
		}
	}
	ans=step[n];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i]-'0';
		num[i]=num[i-1];
		if(!a[i])num[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		T[c[i]]++;
	}
	prepare();
	solve();
	cout<<ans<<'\n';
	return 0;
}
/*
3 2
101
1 1 2
*/
