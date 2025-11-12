#include<bits/stdc++.h>
using namespace std;
map<int,int>p[10005];
int n,m,k,ans,c[15][10005],sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,v;
		cin>>a>>b>>v;
		if(a>b)swap(a,b);
		if(!p[a][b])p[a][b]=v;
		else p[a][b]=min(p[a][b],v);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans+=p[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		int t=0;
		for(int j=1;j<=n;j++)
			cin>>c[i][j],t+=c[i][j];
		sum=min(sum,t);
	}
	
	cout<<min(sum,ans);
	return 0;
}
