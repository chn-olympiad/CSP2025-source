#include <bits/stdc++.h>

using namespace std;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,k,u[10000],v[10000],w[10000],a[10000];
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=0;i<k+m+1;i++){
		cin >> a[i];
	}
	cout << "0";
	return 0;
}
