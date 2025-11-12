#include<iostream>
#include<cstdio>
using namespace std;
long long f[1000005]={},w[1000005]={},c[105]={},a[10005][12]={},dp[1000005]={};
int finn(int p)
{
	if(f[p]==p)
		return p;
	else
		return finn(f[p]);
}
void finnn(long long x,long long y,int i)
{
	int x1,y1;
	if((f[x]==0)&&(f[y]==0))
	{
		f[x]+=x;
		f[y]+=x;
	}
	if((f[x]!=0)&&(f[y]==0))
		f[y]+=x;
	if((f[x]==0)&&(f[y]!=0))
		f[x]+=y;
	if((f[x]!=0)&&(f[y]!=0))
	{
		x1=finn(x);
		y1=finn(y);
		f[x1]=0;
		f[x1]+=f[y1];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x,y;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w[i];
		finnn(x,y,i);	
	}	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int j=m;j>=0;j--)
		dp[j]=1000000007;
	for(int i=1;i<=n;i++)
		for(int j=m-1;j>=1;j--)
			dp[j]=min(dp[j],dp[j-1]-w[i]);
	cout<<1000000007-dp[m-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
