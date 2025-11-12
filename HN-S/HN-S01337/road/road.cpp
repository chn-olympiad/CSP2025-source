#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
struct two
{
	int p;
	int c;
};
vector<two>r[100005];
vector<int>px;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int c[k+1];
	int a[k+1][m+1];
	for(int x,y,w,i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		r[x].push_back({y,w});
		r[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<r[i].size();j++)
			for(int s=1;s<=k;s++)
				if(a[s][i]+a[s][r[i][j].p]+c[k]<=r[i][j].c)
					r[i][j].c=a[s][i]+a[s][r[i][j].p]+c[k];
	for(int i=1;i<=n;i++)
		for(int j=0;j<r[i].size();j++)
			px.push_back(r[i][j].c);
	sort(&px[0],&px[px.size()-1],cmp);
	int ans=0;
	for(int i=0;i<n-1;i++)
		ans+=px[i];
	cout<<ans; 
	return 0;
}
