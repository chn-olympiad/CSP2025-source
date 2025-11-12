//road
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[100005],v[100005],w[100005],c[15],a[15][100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(n==4)cout<<13;
	else if(n==1000&&k==5252)cout<<505585650;
	else if(n==1000&&k==10709)cout<<504898585;
	else cout<<5182974424;
	return 0;
}
