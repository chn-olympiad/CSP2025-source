#include<bits/stdc++.h>
using namespace std;
int a[101],b[11][11],k=0,c,d,z,e,n,m,j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=0;i<c;i++){
		cin>>a[i];
	}
	z=a[0];
	sort(a,a+c);
	for(int i=0;i<m;i++){
	    if(k%2==0){
	    	for(int j=0;j<n;j++){
	    		b[i][j]=a[c-1];
	    		c--;
			}
		}else{
			for(int j=n-1;j>=0;j--){
	    		b[i][j]=a[c-1];
	    		c--;
			}
		}
		k++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==z){
				cout<<i+1<<" "<<j+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
