#include<bits/stdc++.h>
using namespace std;
int c=1,r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m=0,n=0; 
	cin>>m>>n;
	int a[n*m]; 
	int nu=1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[0]<a[i]){
			if(nu%2==0){
				
				if(r<=1){				
					c++;
					nu++;
				}
				r--;
			}
			else{
				r++;
				if(r>=m){
					nu++;
					c++;	
				}
			}
		}	
	}	
	cout<<c<<"  "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
