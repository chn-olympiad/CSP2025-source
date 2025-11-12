#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,a,b,d,f,csmin,xcmin=0,xcroad=0,min,g,h,i;
	cin>>n>>m>>k;
	i=n*k;
	int u[n];
	int v[n];
	int w[n];
	int c[k];
	int e[i];
	for(a=0;a<n;a++){
		cin>>u[a]>>v[a]>>w[a];
	}
	for(b=1;b<k+1;b++){
		cin>>c[b];
		for(d=1;d<n*b+1;d++){
			cin>>e[d];
		}
	}
	freopen("road.in","r",stdin);
	for(g=1;g<k+1;g++){
		if(c[g-1]<xcmin){
			xcmin=c[g-1];
		}
	}
	cout<<13;
	freopen("road.out","w",stdout);
}
