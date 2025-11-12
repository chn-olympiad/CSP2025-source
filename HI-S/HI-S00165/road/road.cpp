#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,c;
	cin>>n>>m>>c;
	long long a[m+1][3];
	for(long long i=1;i<=m;i++)
	{
		for(long long j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	long long b[c][n+2],t=9999999999,x,s[c]={0};
	for(long long i=0;i<c;i++)
	{
		for(long long j=1;j<=n+2;j++)
		{
			cin>>a[i][j];
			s[i]+=a[i][j];
		}
	}
	sort(s,s+c);
	cout<<s[c-1];
	return 0;
}

