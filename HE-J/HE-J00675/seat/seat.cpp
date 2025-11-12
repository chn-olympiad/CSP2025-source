#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int c=1,r=1; 
int main(){
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ra=a[1];
	
	int b=0;
	for(i=2;i<=n*m;i++){
		if(ra<a[i]){
			b+=1;
		}
	}
	for(i=0;i<b;i++){
		if(c%2==1 && r<n){
			r+=1;
		}else{
			if(c%2==1 && r==n){
				c+=1;
			}else{
				if(c%2==0 && r>1){
					r-=1;
				}else{
					if(c%2==0 && r==1){
						c+=1;
					}
				}
			}
		}
	}
	freopen("seat.out","w",stdout); 
	cout<<c<<" "<<r;
	
	
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
} 
