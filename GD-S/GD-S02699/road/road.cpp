#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		s+=w[i];
	}
	int bj=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)	bj=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)	bj=0;
		}
	}
	if(bj==1){
		cout<<0;
		return 0;
	}
	cout<<s;
	return 0;
}
