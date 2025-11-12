#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,m,k,j,i,c,a,b=0,u,v,w,o=0;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(u<v&&u<w){
			b=b+u;
		}
		if(v<u&&v<w){
			b=b+v;
		}
		if(w<v&&u>w){
			b=b+w;
		}
	}
	for(j=1;j<=k;j++){
		cin>>c;
		for(j=1;j<=n;j++){
			cin>>a;
			o=o+a;
		}
	}
	cout<<b+o/3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
