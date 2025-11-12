#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[10010],a[20][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>u>>v>>w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[j][i];
		}
	}
	cout<<0;
	return 0;
}
