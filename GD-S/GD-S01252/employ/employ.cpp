#include<bits/stdc++.h>
using namespace std;
const int maxn=20,mod=998244353;
string qb;
int a[maxn],c[(1<<18)+5][maxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>qb;
	for(int i=1;i<=n;i++)cin>>a[i];
	int o=0;
	for(int i=1;i<=n;i++)o+=qb[i-1]-'0';
	if(o>n-m)
	{
		cout<<0;
		return 0;
	}
	int t=(1<<n)-1;
	c[0][0]=1;
	for(int i=1;i<=t;i++)
	{
		int k=0;
		for(int j=1;j<=n;j++)if((i>>(j-1))&1)k++;
		k=qb[k-1]-'0';
//		cout<<i<<' '<<k<<'\n';
		for(int j=1;j<=n;j++)
		{
			if((i>>(j-1))&1)
			{
				for(int l=0;l<=n;l++)
				{
//					if(i==4)
//					{
//						cout<<l<<' ';
//						if(l>=a[j])cout<<1;
//						else if(k==1)cout<<2;
//						else cout<<3;
//						cout<<'\n';
//					}
					if(l>=a[j])c[i][l+1]+=c[i^(1<<(j-1))][l];
					else if(k==1)c[i][l]+=c[i^(1<<(j-1))][l];
					else c[i][l+1]+=c[i^(1<<(j-1))][l];
					c[i][l+1]%=mod;
					c[i][l]%=mod;
				}
			}
		}
	}
	long long s=0;
	for(int i=m;i<=n;i++)
	{
		s+=c[t][n-i];
		s%=mod;
	}
	cout<<s;
//	cout<<'\n';
//	for(int i=1;i<=t;i++)
//	{
//		for(int j=0;j<=n;j++)cout<<c[i][j]<<' ';
//		cout<<'\n';
//	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
