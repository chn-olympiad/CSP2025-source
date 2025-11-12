#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],R,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=m*n-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			c=i/n+1;
			if(c%2){
				if(i%n==0){
					c--;
					r=1;
				}
				else{
					r=i%n;
				}
			}
			else{
				if(i%n==0){
					c--;
					r=m;
				}
				else{
					r=m-i%n;
				}
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
