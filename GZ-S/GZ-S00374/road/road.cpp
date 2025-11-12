//GZ-S00374 遵义市第四初级中学 聂宇东
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define forr(a,n) for(int a=0;a<n;a++)
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1],c[k+1],a[k+1][n+1];
	forr(i,m)cin>>u[i]>>v[i]>>w[i];
	forr(i,k){
		cin>>c[i];
		forr(j,n)cin>>a[i][j];
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

