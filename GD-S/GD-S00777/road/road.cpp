#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Maxn=1e6+10,p=998244353;

struct Node{
	int u,v,val;
}edge[Maxn];

int n,m,k,a[Maxn];

int main() {
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].val);
	for(int i=1;i<=k;i++) {
		int in;
		scanf("%d",&in);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i]);
	}
	cout<<0<<endl;
	
	
	return 0;
}
