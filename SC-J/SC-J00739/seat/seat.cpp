#include <iostream>
using namespace std;
int a[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int m,n;
	cin>>n>>m;
	if(n==1 && m==1) cout<<1<<" "<<1;
	for(int x=1;x<=n*m;x++){
		cin>>a[x];
	}

	int c[10][10];
	for(int i=1;i<=m;i++){
		if(i%2!=0){
	        for(int j=1;j<=n;j++){
	        	if(i!=1) c[i][j]=1*j+10*(i-2);
	        	if(i==1) c[i][j]=i*j;
	        }
	    }
	    if(i%2==0){
	    	for(int j=n;j>=1;j--){
	    		c[i][j]=1*j+10*(i-2);
			}
		}
		
	}
	return 0;
	fclose("seat.in",stdin);
	fclose("seat.out",stdout);
	
}