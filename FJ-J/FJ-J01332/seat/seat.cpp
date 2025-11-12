#include<bits/stdc++.h>
using namespace std;
int a[11][11],n,m,b[105];
bool paixv(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int c=b[1];
	sort(b+1,b+n*m+1,paixv);
	for(int i=1;i<=m;i++){//i对应列数 
	    if(i%2==1){
		    for(int j=1;j<=n;j++){//j对应行数 
			    a[i][j]=b[(i-1)*n+j];
		    } 
	    }
	    else{
	    	for(int j=n;j>=1;j--){
			    a[i][j]=b[(i-1)*n+(n-j+1)];
		    }
		}
	}
	for(int i=1;i<=m;i++){//i对应列数 
	    if(i%2==1){
		    for(int j=1;j<=n;j++){//j对应行数 
			    if(a[i][j]==c){
			    	cout<<i<<" "<<j;
				}
		    } 
	    }
	    else{
	    	for(int j=n;j>=1;j--){
			    if(a[i][j]==c){
			    	cout<<i<<" "<<j;
				}
		    }
		}
	}
	
	return 0;
}
