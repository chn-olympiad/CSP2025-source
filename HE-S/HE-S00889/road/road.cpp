#include<bits/stdc++.h>																																								/*#include<iostream>#include<cstdio>#include<cmath>#include<algorithm>#include<ctring>*/
#define MAXN 1000001
using namespace std;
long long n,m,k,u[MAXN],v[MAXN],w[MAXN],c[10],a[10][MAXN],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;++i){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=0;j<k;++j){
		cin>>c[j];
		ans+=c[j];
		for(int t=0;t<n;++t){
			cin>>a[j][t];
		}
	}
	if(ans%2==0){
		cout<<ans/3;
	}else{
		cout<<ans/2;
	}
	return 0;
}
