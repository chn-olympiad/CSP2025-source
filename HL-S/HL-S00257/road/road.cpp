#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
int n,m,k;
int u[M],v[M],w[M],c[N];
ull ans=LONG_LONG_MAX;

int main() {
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++) {
		int fee;
		scanf("%d",&fee);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		ans=min(ans,(ull)fee);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}