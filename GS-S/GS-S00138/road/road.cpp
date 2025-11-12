#include<bits/stdc++.h>
using namespace std;
int a[2000005][4];
int c[15][10005];
long long sum;
int v[10005];
int n,m,k;
void so(int t,long long num)
{
	if(t==m+1)
	{
		for(int i=1;i<n;i++)
			if(v[i]!=1)
				return;
		sum=max(num,sum);
		return;
	}
	if(v[a[t][4]-1]==0)
	{
		v[a[t][4]-1]=1;
		so(t+1,num+a[t][3]);
		v[a[t][4]-1]=0;
		so(t+1,num);
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	bool f=1;
	for(int i=1;i<=k;i++)
	{ 
		for(int j=1;j<=n+1;j++)
		{
			cin>>c[i][j];
			if(c[i][1]!=0)
				f=0;
		}
	}	
	so(1,0);
	cout<<sum; 
	return 0;
}
