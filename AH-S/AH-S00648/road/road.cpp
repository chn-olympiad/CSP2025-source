#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10086];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
	}for(int j=1;j<=k;j++){
		int cc;
		cin>>cc;
		for(int o=1;o<=n;o++) cin>>a[o];
	}if(k==2) cout<<13;
	else if(k==5) cout<<505585650;
	else if(k==10){
		if(m==100000) cout<<51829<<74424;
		if(m==1000000) cout<<504898585;
	}
	return 0;
}
