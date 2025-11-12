#include<bits/stdc++.h>
//luogu:1503820
//topscoding:509
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cin.tie(nullptr);
	long long n,m,f,j=1,sc=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		if(j==1)
		{
			for(j;j<=n;++j)
			{
				++sc;
				if(a[sc]==f)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			if(j>n)
			{
				j=n;
			}
		}
		else
		{
			for(j;j>=1;--j)
			{
				++sc;
				if(a[sc]==f)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			if(j<1)
			{
				j=1;
			}
		}
	}
	return 0;
}
/*
 CCCC   CCCC  FFFFF
C      C      F
C      C      FFFF
 CCCC   CCCC  F



			A        CCCCC
		   A A      C    
		  A   A     C
		 AAAAAAA    C    
		A       A    CCCCC
*/
