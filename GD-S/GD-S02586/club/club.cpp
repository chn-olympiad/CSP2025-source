#include<bits/stdc++.h>
using namespace std;
long long t,n,a[101000][4],d[101000],ss;
void dfs(long long c,long long m,long long w,long long s)
{
	if(s==n) 
	{
		ss=max(ss,m);
		return;
	}
	if(w>n/2 && c>3) return;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0)
		{
			d[i]=1;
			if(w<n/2) dfs(c,m+a[i][c],w+1,s+1);
			if(w<=n/2) dfs(c+1,m+a[i][c+1],1,s+1);
			d[i]=0;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		ss=0;
		memset(a,0,sizeof(0));
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		dfs(1,0,0,0);
		cout<<ss<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
