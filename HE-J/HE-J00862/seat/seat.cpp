#include <bits/stdc++.h>
using namespace std;
int a[110][110],b[1010],n,m,ans;
double cmp(int a,int b){
	return a > b;
}
int main(){
	freopen( "seat.in" , "r" , stdin);
	freopen( "seat.out" , "w" , stdout);
	cin>>n>>m;
	for(int i=1 ; i<=n*m ; i++){
		cin>>b[i];
		ans=b[1];
	}
	sort(b+1,b+n*m+1,cmp);
	int k=1;
	for(int i=1 ; i<=m ; i++){
		if(i%2==0){
			for(int j=n ; j>=1 ; j--){
				a[j][i]=b[k];
				k++;
			}
		}
		if(i%2==1){
			for(int j=1 ; j<=n ; j++){
				a[j][i]=b[k];
				k++;
			}	
		}		
	}
	for(int i=1 ; i<=m ; i++){
		for(int j=1 ; j<=n ; j++){
			if(a[i][j]==ans){
				cout<<j<<" "<<i;
				break;
			}			
		}
	}	
	return 0;
}

