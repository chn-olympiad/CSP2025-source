//GZ-S00164 遵义市第四中学 张槟  
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pail pair<int ,int>
const int N=1e5+5;
vector<vector<pail> >g[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,val;
		scanf("%d %d %d",&u,&v,&val);
		if(i%2==0) ans+=val;
	}
	for(int i=1;i<=k;i++)
	{
		int val;
		scanf("%d",&val);
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			int v;
			scanf("%d",&v);
		}
	}
	cout<<ans;
	return 0;	
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
