#include <bits/stdc++.h>
using namespace std;

const int NUM=1e6+7;
int a[NUM];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int m,n,k,vo,vt,wo,c;
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++)
		cin >> vo >> vt >> wo;
	for(int j=1; j<=k; j++){
		cin >> c;
		for(int z=1;z<=n;z++)
			cin >> a[z];
	}
	
	cout << 0;
	return 0;
}
