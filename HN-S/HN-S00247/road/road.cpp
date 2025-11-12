#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m,k,a,b,c[100000],xum=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c[i];
		xum+=c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>a>>a>>a>>a>>a>>a;
	}
	cout<<xum;
}
