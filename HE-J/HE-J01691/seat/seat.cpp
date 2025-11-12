#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],b[11][11],k=1,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];	
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j+=2){
		for(int i=1;i<=n;i++){
		    b[i][j]=a[k];
			k++;
	    }
	    k+=n;
	}
	
	k=n+1;
	for(int j=2;j<=m;j+=2){
		for(int i=n;i>=1;i--){	  
		    b[i][j]=a[k];
		    k++;
	    }
	    k+=n;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		    if(b[i][j]==ans){
		    	cout<<j<<" "<<i;
		    	return 0;
			}
	    }
	}
	return 0;
}
