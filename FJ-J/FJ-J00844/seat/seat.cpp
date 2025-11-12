#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,g=0,h=1,i,j,k[1000004];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	cin>>c;
	for(i=1;i<a*b;i++){
		cin>>k[i];
	}
	for(i=1;i<a*b;i++){
		if(c<k[i]){
			h++;
		}
	}
	for(i=1;i<=a;i++){
	if(i%2==1){
		for(j=1;j<=b;j++){
			g++;
			if(g==h){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}else{
		for(j=b;j>=1;j--){
			g++;
			if(g==h){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}	
	}
	return 0;
} 
