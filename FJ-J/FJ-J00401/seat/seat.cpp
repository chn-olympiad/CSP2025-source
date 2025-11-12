#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,z,l=1,bn,bm; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]>a[1]){
				l++;
			}
		}
	} 
	if(l%n>0){
		bm=l/n+1;
	}else{
		bm=l/n;
	} 
	if(bm%2==1){
		if(l%n==0){
			bn=n;
		}else{
			bn=l%n;
		}
	}else{
		if(l%n!=0){
			bn=n+1-(l%n);
		}else{
			bn=1;
		}
	}
	cout<<bm<<" "<<bn;
	return 0;
}
