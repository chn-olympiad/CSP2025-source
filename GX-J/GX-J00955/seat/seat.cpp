#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n][m]={},i,j,b[n*m]={},c,d=0;
	for(i=0;i<n*m;i++){
		cin>>b[i];
	}
	int k=b[0];
	for(i=0;i<n*m;i++){
		for(j=i+1;j<n*m;j++){
			if(b[i]<b[j]){
				c=b[i];
				b[i]=b[j];
				b[j]=c;
			}
		}
	}
	c=1;
	while(d<n*m){
		if(c%2!=0){
			for(i=0;i<n;i++){
				a[i][c-1]=b[d];
				d++;
				if(a[i][c-1]==k){
					cout<<c<<" "<<i+1;
					d=n*m+1;
					break;
				}
			}
		}
		if(c%2==0){
			for(i=n-1;i>=0;i--){
				a[i][c-1]=b[d];
				d++;
				if(a[i][c-1]==k){
					cout<<c<<" "<<i+1;
					d=n*m+1;
					break;
				}
			}
		}
		c++;
	}
	return 0;
}
