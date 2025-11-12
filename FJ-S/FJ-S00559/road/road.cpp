#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[100000010],v[100000010],w[100000010],c[100000010],a[100000010][100000010];
int main(){
	reopen("road.in","r",stdin);
	reopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	} 
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i++){
			cin>>c[j]>>a[j][i];
		}	
	}
	return 0;
}
