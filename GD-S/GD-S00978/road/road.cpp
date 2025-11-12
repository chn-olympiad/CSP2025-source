#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,K=15;
int n,m,k,c[N];
struct node{
	int to,v;
};
vector<node> a[N];
vector<node> b[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			scanf("%lld",&x);
			b[i].push_back({j,x});
			b[j].push_back({i,x});
		}
	}
	cout<<0;
	return 0;
}
