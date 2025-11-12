#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define TNF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,k;
vector<pii>v[1000010];
int c[15];
int d[1000010];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		v[a].push_back({b,w});
		v[b].push_back({a,w});
	}
	int sum=0;
	for(int i=1;i<=n;i++) 
	{
		int mx=-TNF;
		for(auto j:v[i])
		{
			mx=max(mx,j.second); 
		}
		sum+=mx;
	}
	cout<<sum/2<<endl;
	return 0;
} /*
4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4
*/
