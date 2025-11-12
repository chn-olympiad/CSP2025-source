#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],s,p[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//思路：乡村城镇化和新建道路是算作一条道路 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	if(k){
		for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=m;i++){
		for(int j=m;j>0;j++){
			p[j]=w[i];
		}
	} 
	for(int i=1;i<n;i++){
		s+=p[i];
	}
	cout<<s;
	return 0;
}
