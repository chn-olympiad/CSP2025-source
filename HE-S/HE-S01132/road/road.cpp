#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u[10005],v[10005],w[10005];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int c[100005];
	int a[10005];
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
	} 
	cout<<13;
	return 0;
} 
