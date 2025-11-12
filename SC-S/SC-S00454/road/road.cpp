#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r[1000005][5],v[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,ans;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i][1]>>r[i][2]>>r[i][3];
		ans+=r[i][3]; 
	} 
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>v[i][j];
	}
	cout<<ans;
	return 0;
}
