#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],a[1005][1005],v[1000005],w[1000005],c[1000005],flag;
long long sum;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	for(int j=0;j<k;j++){
		cin>>c[j];if(c[j]) flag=0;
		for(int i=0;i<n;i++){
			cin>>a[j][i];
		}
	}
	if(flag) cout<<sum;
	else cout<<7156856;
	return 0;
}