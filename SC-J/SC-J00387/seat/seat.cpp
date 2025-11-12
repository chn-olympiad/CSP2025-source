#include<bits/stdc++.h>
using namespace std;
int n,m;
int k[101],t[101];

int f,l=0,dp[11][11];
//int cnt1=0,cnt2=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>k[i];
	f=k[0];
	for(int i=0;i<n*m;i++)
		++t[k[i]];
	for(int i=100;i>=0;--i)
	{
		if(t[i])
		{
			k[l]=i;
//			cout<<k[j]<<' ';
			
			l++;
		}
	}
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;j++)
		{
			dp[j][i]=k[i*m+j];
//			cout<<i<<" "<<j<<endl;
		}
		i++;
		for(int j=n-1;j>=0;j--)
		{
			dp[j][i]=k[i*m+n-j-1];
//			cout<<i<<" "<<j<<endl;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
//			cout<<setw(4)<<dp[j][i]<<' ';
//		cout<<endl;
		if(dp[j][i]==f)
		{
			cout<<i+1<<' '<<j+1;
			break; 
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/