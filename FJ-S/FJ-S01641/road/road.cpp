#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,a,s,u,v,w[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
	}	
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}sort(w+1,w+1+m);
	for(int i=1;i<n;i++){
		s+=w[i];
	}
	cout<<s;
}
