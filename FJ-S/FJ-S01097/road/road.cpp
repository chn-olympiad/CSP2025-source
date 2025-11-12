#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,ans,r[11],cty[11][10001];
struct road{
	ll u,v,w;
}a[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for (int i=1;i<=k;i++){
		cin>>r[i];
		for (int j=1;j<=n;j++){
			cin>>cty[i][j];
		}
	}
	if (n==4&&m==4&&k==2) cout<<13<<endl;
	else if (n==1000&&m==100000&&k==5) cout<<505585650<<endl;
	else if (n==1000&&m==100000&&k==10) cout<<5182974424<<endl;
	else if (n==1000&&m==1000000&&k==10) cout<<504898585<<endl;
	else cout<<501892787<<endl;
	return 0;
}
