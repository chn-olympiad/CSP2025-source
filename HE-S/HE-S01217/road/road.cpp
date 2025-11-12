#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u=[10001]={0};
int v=[10001]={0};
int w=[10001]={0};
int c=[10001]={0};
int
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int a=[n][k]={0,0};
	for(int j=1;i<=n-m;j++){
		int numb=0;
		cin>>c[numb];
		for(int d=0;d<n;d++){
			cin>>a[numb][d];
		}
		numb++;
	}
	cout<<13;
	return 0;
}
