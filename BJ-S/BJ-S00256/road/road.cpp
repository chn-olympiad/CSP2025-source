#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10,M=1e4+10;

struct node
{
	int u,v,w;
};

int n,m,k,ans;
int e[M][M];//m[x][y]表示从x到y的钱
int f[M];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		ans+=z;
	}
	cout<<ans;
	return 0;
}
