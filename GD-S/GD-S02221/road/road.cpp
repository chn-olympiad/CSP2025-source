#include <bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e6+5;
int n,m,k;
struct Node{
	int x,y;
	long long z;
}edge[M];
long long a[11][N];
int fa[N];
int Find(int x) {
	if (x==fa[x]) return x;
	return fa[x]=Find(fa[x]);
}
vector<Node> ve;
int cmp(Node n1,Node n2) {
	return n1.z<n2.z;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++) {
		scanf("%d %d %lld",&edge[i].x,&edge[i].y,&edge[i].z);	
	}
	int flag=1;
	for (int i=1;i<=k;i++) {
		for (int j=0;j<=n;j++) {
			scanf("%lld",&a[i][j]);
			if (a[i][j]!=0) flag=0;
		}
	}
	if (flag==1) {
		printf("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	long long ans=1e18;
	for (int s=0;s<(1<<k);s++) {
		ve.clear();
		for (int i=1;i<=m;i++) {
			ve.push_back(edge[i]);
		}
		long long sum=0;
		for (int i=1;i<=k;i++) {
			if ((s&(1<<(i-1)))!=(1<<(i-1))) {
				continue;
			} 
			sum+=a[i][0];
			for (int j=1;j<=n;j++) {
				ve.push_back({i+n,j,a[i][j]});
			}
		}
		sort(ve.begin(),ve.end(),cmp);
		for (int i=1;i<=n+k;i++) {
			fa[i]=i;
		}
		for (int i=0;i<ve.size();i++) {
			int u=Find(ve[i].x);
			int v=Find(ve[i].y);
			if (u==v) continue;
			sum+=ve[i].z;
			fa[u]=v;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

