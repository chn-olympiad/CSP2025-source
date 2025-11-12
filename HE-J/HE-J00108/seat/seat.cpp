#include<bits/stdc++.h>
using namespace std;
int p=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a[105],b[15][15],k;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	k=a[1];
    	a[1]=a[1];
	} 
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2!=0){
		    for(int i=1;i<=n;i++){
		    	p+=1;
		    	b[i][j]=a[p];
		    }
		}
		else{
		    for(int i=n;i>=1;i--){
		    	p+=1;
			    b[i][j]=a[p];
		    }
	    }
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k==b[i][j]){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
