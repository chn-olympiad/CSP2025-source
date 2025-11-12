#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],x[10][10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int k=1;
	int a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2!=0){
				x[i][j]=a[k];
		        k++;
			}
		    if(j%2==0){
				x[j][i]=a[k];
		        k++;
			}
	    } 
	} 
    for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
		    if(x[j][i]==a1){
		    	cout<<i<<" "<<j;
		    	return 0;
			} 
	    } 
	} 
} 
