#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10003],w[1000000],v[100000000],c[1000][100000],l;
int main(){
	freopen("road.in","r",stdin);
	freopen("road","r",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cout<<c[i][0];
		if(c[i][0]==0){
			l++;
		}
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
    if(l==k){
	cout<<0<<endl;
	}
	return 0;
}
