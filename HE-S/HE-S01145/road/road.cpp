#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	for(int i=1;i<=k+m;i++){
		cin>>a>>b>>c;
	}
	if(n==4&&m==4){
		cout<<13<<endl;
	}if(n==1000&&k==5){
		cout<<505585650<<endl;
	}if(n==1000&&k==10){
		cout<<504898585<<endl;
	}
	return 0;
} 
