#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[m*n];
    int b[m+1][n+1];
    for(int i=0;i<m*n;i++){
    	cin>>a[i];
	}
	int z=a[0];
	for(int i=0;i<m*n;i++){
		for(int o=i+1;o<m*n;o++){
			if(a[i]<a[o]){
    			int q=a[i];
    			a[i]=a[o];
    			a[o]=q;
    		}
		}
	}	
	int j=1;
	int k=1;
	int i=0;
	while(j<=m && k<=n){
		while(k<n+1){
			b[j][k]=a[i];
			i++;
			k++;
		}
		j++;
		k--;
		if(j>m){
			break;
		}	
		while(k>0){
			b[j][k]=a[i];
			i++;
			k--;
		}
		j++;
		k++;
		if(j>m){
			break;
		}				
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=m;o++){
			if(b[o][i]==z){
				cout<<o<<" "<<i;
				break;
			}
		}
	}
    return 0;
}