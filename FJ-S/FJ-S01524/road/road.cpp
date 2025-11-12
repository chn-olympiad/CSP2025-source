#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c1[15],c2[15],c3[15],c4[15],c5[15],sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c1[i]>>c2[i]>>c3[i]>>c4[i]>>c5[i];
	}
	cout<<sum;
	return 0;
}

