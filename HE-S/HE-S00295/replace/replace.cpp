#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50;
int n,m,k;
vector<vector<int> >vv,fy[N];
int a[15][N];
int c[N],w[N],z[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v>>w[i]; 
		cnt++;
		z[cnt]=w[i];
	}
	sort(w+1,w+1+n);
	long long anss=0;
	for(int i=1;i<n;i++)
	{
		anss+=w[i];
	}
	long long ansx=2e16;
	for(int i=1;i<=k;i++)
	{
		long long ans=0;
		cin>>c[i];
		ans+=c[i];
		cnt++;
		z[cnt]=c[i];
		for(int j=1;j<=n;j++)
		{
			cnt++;
			cin>>a[i][j];
			ans+=a[i][j];
			z[cnt]=a[i][j];
		}
		ansx=min(ans,ansx);
	}
	sort(z+1,z+1+cnt);
	long long ansss=0;
	for(int i=1;i<=n+1;n++)
	{
		ansss+=z[i];
	}
	cout<<min(min(ansx,anss),ansss)<<endl;
	return 0;
} 
//Ren5Jie4Di4Ling5%
