#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e4+5;
const LL inf = 0x3f3f3f3f3f3f3f3f;
LL n,m,k,u,v,d,c[12],ca[12][N],cnt;
vector<node> ve[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(x,inf,sizeof x);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>d;
		cnt+=d;
		ve[u].push_back({v,d});
		ve[v].push_back({u,d});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>ca[i][j];
		}
	}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
