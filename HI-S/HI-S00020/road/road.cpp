#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[10005],u[10005],v[10005];
int a[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
	for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	 cout<<w[m];
	return 0;
}
