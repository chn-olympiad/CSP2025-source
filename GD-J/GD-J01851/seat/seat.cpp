#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[15][15];
int sum[110];
int paixu[110];
int t=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;++i)
	{
		cin>>sum[i];
	}
	int cj=sum[1];
	sort(sum+1,sum+1+nm);
	for(int i=nm;i>=1;--i)
	{
		paixu[t]=sum[i];
		t++;
	}
	for(int i=1;i<=nm;++i)
	{
		sum[i]=paixu[i];
	}
	for(int i=1;i<=nm;++i)
	{
		for(int l=1;l<=m;++l)
		{
			if(i<=n*l&&i>(n*(l-1)))
			{
				if(l%2==1)
				{
					st[l][i-((l-1)*n)]=sum[i];
				}
				else
				{
					int tmp=i-((l-1)*n);
					st[l][n-tmp+1]=sum[i];
				}
			}
		} 
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(st[j][i]==cj)
			{
				cout<<j<<" "<<i<<'\n';
			}
		}
	}
	return 0;
}
