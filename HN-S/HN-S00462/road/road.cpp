#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0,u[1100000],v[1100000],w[1100000],c[1100000],a[1100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int minx=1e9;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		minx=min(minx,c[i]);
		for(int j=1;j<=n;j++){
			cin>>a[i];           
		}
	}
	sum+=minx;
	int minx1[1100000]={},minx2[1100000]={};
	for(int i=1;i<=m;i++){
		minx1[v[i]]=min(minx1[v[i]],w[i]);
	}
	for(int j=1;j<=k;j++){
	    for(int i=1;i<=m;i++){
		    minx2[i]=min(minx2[i],a[i]);
	    }
    }
    for(int i=1;i<=n;i++){
    	sum+=min(minx1[i],minx2[i]);
	}
	cout<<sum;
	return 0;
}
