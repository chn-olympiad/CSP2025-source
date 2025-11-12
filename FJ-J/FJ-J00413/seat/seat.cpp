#include<bits/stdc++.h>
using namespace std;
int x[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,a1=0,k=100;
	cin>>n>>m;//n––m¡– 
	for(int i=1;i<=n*m;i++){
		cin>>c;
		x[c]=1;
		if(i==1) a1=c;
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				for(;x[k]!=1;k--);
				if(k==a1){
				cout<<i<<" "<<j;
				return 0; 
			    }
			    k--;
			}
		}else{
			for(int j=1;j<=n;j++){
				for(;x[k]!=1;k--) x[k]=0;
				if(k==a1){
				cout<<i<<" "<<j;
				return 0; 
			    }
			    k--;
			}
		}
	}
}
