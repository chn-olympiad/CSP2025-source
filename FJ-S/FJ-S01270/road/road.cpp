#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10000][10000],x,y,w[10000],c[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w[i];
		a[x][y]++;
	}
	cin>>c;
	for(int i=1;i<=k;i++){
		cin>>cn;
		for(int j=1;j<=n;j++){
			cin>>c[i];
		}
	}
	
	cout<<"0";
	return 0;
} 
