#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	if(k == 0){
		if(m == 1){
			cout << w[1];
			
		}
		if(m == 2){
			w[1]+=w[2];
			cout << w[1];
		}
		return 0;
	}
	return 0;
}
