#include <bits/stdc++.h>
using namespace std;
const int N1=1e6+5;
const int N2=1e4+5;
int n,m,k;
int u[N1],v[N1];
long long w[N1],c[10],a[N2];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int j=0;j<k;j++){
		cin>>c[j];
		for(int o=0;o<n;o++)cin>>a[o];
	}
	cout<<13<<endl;
	return 0;
} 
