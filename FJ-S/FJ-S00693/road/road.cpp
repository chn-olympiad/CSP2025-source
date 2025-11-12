#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int v;
	ll w;
	node(int a,ll b){
		v=a,w=b;
	}
};
int n,m,k;
vector<node> edges[10010];
ll c[12],a[12][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;ll z;
		scanf("%d%d%lld",&x,&y,&z);
		edges[x].push_back(node(y,z));
		edges[y].push_back(node(x,z));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}	
}
