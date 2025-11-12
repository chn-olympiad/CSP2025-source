#include<bits/stdc++.h> 
//#define int long long
using namespace std;
const int maxn=5e3+5,mod=998244353;
int n,m,a[maxn];
int c[2*maxn+5],d[2*maxn+5];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int m=a[n]*2;
	c[0]=1;
	long long s=0,k;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m+1;j++)d[j]=0;
		for(int j=m+1;j>=0;j--)
		{
			int t=j+a[i];
			if(t>m)t=m+1;
			k=d[t]+c[j];
			k%=mod;
			d[t]=k;
			k=c[t]+c[j];
			k%=mod;
			c[t]=k;
		}
		for(int j=2*a[i]+1;j<=m+1;j++)
		{
			s+=d[j];
			s%=mod;
		}
//		for(int j=0;j<=m+1;j++)
//		{
//			cout<<d[j]<<' ';
//		}
//		cout<<'\n';
//		for(int j=0;j<=m+1;j++)
//		{
//			cout<<c[j]<<' ';
//		}
//		cout<<'\n';
//		cout<<'\n';
	}
	cout<<s;
//	cout<<'\n';
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=m+1;j++)cout<<c[i][j]<<' ';
//		cout<<'\n';
//	}
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

4
1 1 1 1
*/
