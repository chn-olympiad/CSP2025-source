#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define ll long long
using namespace std;
const int M=1e5+5;
int t,n,a[M][5],b[M],len;
ll ans;
vector<int> g[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
				scanf("%d",&a[i][j]);
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=maxx;
			for(int j=1;j<=3;++j)
				if(maxx==a[i][j])
				{
					maxx=-1e9;
					for(int k=1;k<j;++k)maxx=max(maxx,a[i][k]-a[i][j]);
					for(int k=j+1;k<=3;++k)maxx=max(maxx,a[i][k]-a[i][j]);
					g[j].push_back(maxx);
					break;
				}
		}
		if(g[1].size()>n/2)
		{
			sort(g[1].begin(),g[1].end());len=g[1].size()-n/2;
			for(int i=g[1].size()-1;i>=g[1].size()-len;--i)ans+=g[1][i];
		}
		if(g[2].size()>n/2)
		{
			sort(g[2].begin(),g[2].end());len=g[2].size()-n/2;
			for(int i=g[2].size()-1;i>=g[2].size()-len;--i)ans+=g[2][i];
		}
		if(g[3].size()>n/2)
		{
			sort(g[3].begin(),g[3].end());len=g[3].size()-n/2;
			for(int i=g[3].size()-1;i>=g[3].size()-len;--i)ans+=g[3][i];
		}
		printf("%lld\n",ans);
		g[1].clear();
		g[2].clear();
		g[3].clear();
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

4
4 2 1
3 2 4
5 3 4
3 5 1


*/
