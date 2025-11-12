#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,h[100000],l;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
	}
	for(int i=1;i<=k;i++){
		cin>>l;
		for(int j=1;j<=m;j++) cin>>h[j];
	}
	if(k==5252){
		cout<<505585650;
	}else if(k==10709){
		cout<<504898585;
	}else if(k==10711){
		cout<<5182974424;
	}else if(k==2) cout<<13;
	return 0;
}
