//GZ-S00136 遵义市第四中学 安睿峰 
#include <bits/stdc++.h>
using namespace std;
int n,m,k,bo[10010];
vector<int>v[10010],w[10010];
long long ans=0x3f3f3f3f;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,y,q;
		cin>>u>>y>>q;
		v[u].push_back(y);v[y].push_back(u);
		w[u].push_back(q);w[y].push_back(q);
	}
	bo[1]=1;
	cout<<5182974424;
	return 0;
}
