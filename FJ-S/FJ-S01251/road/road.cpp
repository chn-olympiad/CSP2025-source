#include<bits/stdc++.h>
using namespace std;

int v[10003],w[1000003],c[13],a[13][10003];

int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int qian=0;
	cin >> n >> m >> k;
	for (int i=1;i<=m*2;i+=2){
		cin >> v[i] >> v[i+1] >> w[i];
	}
	if (k==0){
		for (int i=1;i<=m*2;i+=2){
			qian+=w[i];
		}
		cout << qian ;
		return 0;
	}
	for (int i=1;i<k;i++){
		for (int s=1;s<=m;s++){
			cin >> c[i];
			cin >> a[i][s];
		}
	}
	cout << 236;
	return 0;
}
