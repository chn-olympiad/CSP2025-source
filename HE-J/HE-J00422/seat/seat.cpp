#include<bits/stdc++.h>
using namespace std;
int n,m,x[102],z=0,z1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n+1][m+1];
	for(int j=1;j<=n*m;j++){
		cin>>x[j];
		if(z==0){
			z=x[j];
		}
	}
	sort(x+1,x+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(x[i]==z){
			z1=n*m+1-i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				z1--;
			    if(z1==0){
			    cout<<i<<" "<<j;	
				}
		    }
		}
		if(i%2==1){
			for(int j=1;j<=n;j++){
				z1--;
				if(z1==0){
					cout<<i<<" "<<j;
				}
		    }
		}
	}
	return 0;
}
