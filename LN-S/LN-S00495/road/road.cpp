#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+5,M=1e6+5;
int n,m,k;
LL ans;
struct road{
	int u,v,w;
	}rd[M];
struct cns{
	int c,mon[N];
	}vill[15];
int main(){  
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&rd[i].u,&rd[i].v,&rd[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&vill[i].c);
		for(int j=1;j<=n;j++)scanf("%d",&vill[i].mon[j]);
		}
	for(int i=1;i<=m;i++)ans+=rd[i].w;
	printf("%lld",ans);
	return 0;
	}
