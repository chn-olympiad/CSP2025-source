#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.on","r",stdin);
	freopen("seat.out","w",stdout);
	int  n,m;
	cin>>n>>m;
	int g=n*m;
	int  a[g];
	int b=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			b+=1;
		}
		if(a[i]<=a[0]){
			b+=0;
			}
}
	int c=b/n+1;
	int h=b%n;
	int r=0;
	if(c%2==0){
		if(h==0){
			r=n;
		}else if(h!=0){
			r=n;
		}		
	}else if(c%2==1){
		if(h==0){
			r=1;
			}else if(h!=0){
				r=n-h+1;
				}
	}
	cout<<c<<" "<<r;
	return 0;
}
