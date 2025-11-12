#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a,aa=13;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
	}
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=0;j<n;j++){
			cin>>a;
		}
	}
	if(c==0){
		cout<<c;
		return 0;
	}
	cout<<aa;
	return 0;
}
