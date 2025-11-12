#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,R,k;
	cin>>c>>r;
	int a[c*r+1];
	for(int i=0;i<c*r;i++){
		cin>>a[i];
	}
	R=a[0];
	for(int i=0;i<c*r;i++){
		for(int i=0;i<c*r-1;i++){
			if(a[i]<a[i+1]){
				k=a[i];
				a[i]=a[i+1];
				a[i+1]=k;
			}
		}
	}
	for(int i=0;i<c*r;i++){
		if(a[i]==R){
			R=i+1;
		}
	}
	int n=1;
	for(int i=1;i<=c;i++){
		if(i%2==1){
			for(int j=n;j<n+c;j++){
				if(j==R){
					cout<<i<<' '<<R-(i-1)*c;
					return 0;
				}
			}
		}
		else{
			for(int j=n+c-1;j>=n;j--){
				if(j==R){
					cout<<i<<' '<<i*c-R+1;
					return 0;
				}
			}
		}
		n=n+c;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
