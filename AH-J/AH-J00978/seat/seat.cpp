#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,i,j,a[i][j];
    cin>>n>>m;
    for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
	    	if(a[i][j]=a[i]*a[j]){
			   cout<<c<<r;	
			}	
		}
	}
	    return 0;
}
