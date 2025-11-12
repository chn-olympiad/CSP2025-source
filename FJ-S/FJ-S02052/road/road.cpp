#include <bits/stdc++.h>
using namespace std;
long long n,m,u[1000005],v[1000005],w[1000005],k,a[1000005],c[15],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[j];
			ans+=a[j];
		}
	}
	cout<<(ans+1)/2;
	return 0;
}

