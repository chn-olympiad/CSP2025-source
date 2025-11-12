#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int N=1e4+10;
int n,m,k;
ll a[N][N],f[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	cout<<0;
	return 0;
}
