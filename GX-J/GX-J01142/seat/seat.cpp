#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,c=1,r=1,y=1,a[105];
	cin>>n>>m>>x;
	a[0]=x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if(a[j]>a[i]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	} 
	for(int i=0;i<n*m;i+=n*2){
		c=1;
		if(i!=0){
			r++;
		}
		for(int j=0;j<n;j++){
			if(a[i+j]==x){
				cout<<r<<" "<<c;
				y=0;
				break;
			}
			c++;
			if(y==0){
				break;
			}
		}
		if(y==0){
				break;
			}
		r++;
		int l=i;
		for(int j=n+l;j<n+l+n;j++){
			c--;
			if(a[j]==x){
				cout<<r<<" "<<c;
				y=0;
				break;
			}
			if(y==0){
				break;
			}
		}
		if(y==0){
				break;
			}
	} 
	
	
	return 0;
}
