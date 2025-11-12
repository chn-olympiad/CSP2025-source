#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6000,mod=998244353;
int n,a[N],f[N][3],ans;
int Pow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m)
{
	if(m==0)return 1;
	if(m==1)return n;
	if(m==2)return n*(n-1)%mod*Pow(2,mod-2)%mod; 
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//	cout<<'\n';
//	for(int i=1;i<=5000;i++)f[0][i]=-1;
	f[0][0]=1;
	for(int i=1;i<n;i++)
	{
//		f[i][0][0]=1;
		for(int ci=2;ci;ci--)
		{
			for(int j=5000;j>=a[i];j--)
			{
//				f[j][ci]=f[j][ci];
	//				if(f[i][j]==-1)f[i][j]=0;
					f[j][ci]+=f[j-a[i]][ci-1],f[j][ci]%=mod;
					if(ci==2)f[j][ci]+=f[j-a[i]][ci],f[j][ci]%=mod;
			}
		}
		int zo=0;
//		for(int j=0;j<=2;j++)
//		{
//			for(int k=0;k<=10;k++)cout<<f[i][k][j]<<' ';
//			cout<<'\n';
//		}
//		cout<<"____________\n";
		for(int j=0;j<=a[i+1];j++)zo+=f[j][2],zo%=mod;
//
//		cout<<f[i][j]<<' ';cout<<'\n';
		if(i<2)continue;
//		cout<<Pow(2,i)-C(i,0)-C(i,1)<<' '<<zo<<'\n';
		ans+=(Pow(2,i)-C(i,0)-C(i,1)-zo)%mod;ans%=mod;
	}
//	cout<<pow(2,20)<<'\n';
	cout<<(ans%mod+mod)%mod;
	return 0;
}
