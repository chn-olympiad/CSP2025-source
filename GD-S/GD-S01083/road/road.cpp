#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int c[N],a[15][10005],vis[N];
long long ans=0;
struct NODE{
	int v,w;
};
vector<NODE>e[N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		NODE nod1,nod2;
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		ans+=ww;
		nod1.v=vv;
		nod1.w=ww;
		nod2.v=uu;
		nod2.w=ww;
		e[uu].push_back(nod1);
		e[vv].push_back(nod2);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	} 
	cout<<ans;
	return 0;
}
