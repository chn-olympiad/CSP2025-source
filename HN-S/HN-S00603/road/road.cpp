#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005];
long long h[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,0,sizeof(h));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	    cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	    for(int j=1;j<=n;j++)
	        cin>>a[i][j];
	int sum=0;
	for(int i=1;i<=m;i++)
		sum+=w[i];
	cout<<sum;	
	return 0;
}

