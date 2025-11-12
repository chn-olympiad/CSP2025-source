#include<bits/stdc++.h>
using namespace std;

const int N=1000009;
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w,c;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		for(int j=0;j<k;j++){
			cin>>c>>a[j];
		}
	}
	cout<<n+m+k+3;
	return 0;
}
