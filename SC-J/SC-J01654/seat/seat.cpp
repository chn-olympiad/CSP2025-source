#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105],b[105];
	int x,y;
	for(int i=1;i<=n*m;i++){
		cin>>a[i-1];
		
	}
	x=a[0];
	sort(a,a+n*m);
	int c=0;
	for(int i=n*m;i>=1;i--){
		b[c]=a[i-1];
		c++;
	} 
	for(int i=0;i<n*m;i++){
		if(b[i]==x){
			y=i+1;
			break;
		}
	}
	int aa=y/n;
	int bb=y%n;
	if(bb==0){
		if(aa%2==0){
			cout<<aa<<" "<<"1";
		}
		else{
			cout<<aa<<" "<<n;
		} 
	}
	else{
		if((aa+1)%2==0){
			cout<<aa+1<<" "<<n-bb+1;
		}
		else{
			cout<<aa+1<<" "<<bb;
		}
	}
	

	
	return 0;
}