#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,mon;
	cin>>n>>m>>k;
	int a[n],b[m],c[k],u[k],v[k];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<m;j++){
		cin>>b[j];
	}
	for(int h=0;h<=k;h++){
		cin>>c[h];
	}
	for(int i=0;i<=k;i++){
		cin>>u[i]>>v[i];
	}
	if(n>k){
		mon=b[m]*c[k]
		cout<<mon<<endl;
	}
	else{
		mon=b[m]*c[k]+(k-m)*u[i];
		cout<<mon<<endl;
	}

	return 0;
}
