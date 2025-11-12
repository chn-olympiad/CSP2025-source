#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+5;
const int M=1e6+5;
vector<int> ve[N];
long long w[M],c[15],a[15][N];
bool op=false;
bool opa=false;
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
		cin>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0)
			{
				op=true;
			}
		}
		if(c[i]!=0||op)
		{
			opa=true;
		}
	}
	if(!opa)
	{
		cout<<ans; 
	}
	else if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			ans+=w[i];
		}
		cout<<ans;
	}
	else
	{
		
	}
	return 0;
}
