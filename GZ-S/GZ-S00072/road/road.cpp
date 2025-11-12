//GZ-S00072 贵阳中天中学 卓然 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
