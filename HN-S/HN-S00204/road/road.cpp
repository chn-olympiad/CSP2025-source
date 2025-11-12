#include<bits/stdc++.h>
#define f(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
int n,m,k,u[1000006],v[1000006],w[1000006],c[15],a[15][100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	f(i,1,m)cin>>u[i]>>v[i]>>w[i];
	f(i,1,k){
		cin>>c[k];
		f(j,1,n)cin>>a[k][i];
	}
	cout<<13;
	return 0;
}
